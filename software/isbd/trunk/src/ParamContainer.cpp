#include <stdio.h>
#include "ParamContainer.h"

// ������������-��������� ������ ��� ������������� getcwd
#ifdef _WIN32
 #include <direct.h>
#else
 #include <unistd.h>
 #define stricmp strcasecmp
 #include <string.h>
 #include <stdlib.h>
#endif

#include <vector>

/*
������� �������������� ����� � ������
*/
static void absToRelPath(std::string spath, std::string &tpath)
{
	int i,j,k,s;
	const char *div;
	if(!spath.length()) return;
	if(spath[0]=='/')
	{
		// Unix
		i=1;
		s=0;
		div="/";
	} else
		if(spath[1]==':') // Windows
		{
			if(tolower(spath[0])!=tolower(tpath[0])) // ������ �����
				return;
			i=3;
			s=2;
			div="\\";
		}
	while(1)
	{
		j=(int)spath.find_first_of(div, i);
		k=(int)tpath.find_first_of(div, i);
		if(j==-1)
		{
			tpath=tpath.substr(i);
			return;
		}
		if(j==k && ((div[0]=='\\' && !stricmp(spath.substr(i, j-i).c_str(), tpath.substr(i, k-i).c_str())) || (div[0]=='/' && spath.substr(i, j-i)==tpath.substr(i, k-i))))
		{
			i=j+1;
			continue;
		}
		if((int)spath.find_first_of(div, j+1)==-1)
		{
			tpath=".."+(div+tpath.substr(i));
		} else
			tpath=tpath.substr(s);
		return;
	}
}

static void relToAbsPath(std::string spath, std::string &tpath)
{
	const char *div;
	int s;
	if(spath[0]=='/')
	{
		// Unix
		if(tpath[0]!='/') tpath=spath.substr(0, spath.find_last_of("/")+1)+tpath;
		div="/";
		s=0;
	} else
		if(spath[1]==':')
		{
			// Windows
			if(tpath[1]!=':')
			{
				if(tpath[0]!='\\')
				{
					tpath=spath.substr(0, spath.find_last_of("\\")+1)+tpath;
				} else
				{
					tpath=spath.substr(0, 2)+tpath;
				}
			}
			div="\\";
			s=2;
		}
	int i,j;
	if(div[0]=='\\')
		for(i=s;i<(int)tpath.length();i++)
			if(tpath[i]=='/') tpath[i]='\\';
	for(i=s;i<(int)tpath.length();)
	{
		if(tpath.substr(i, 4)==std::string(div)+".."+div)
		{
			if(i>s)
				j=(int)tpath.find_last_of(div, i-1);
			else
				j=s;
			tpath=tpath.substr(0, j)+tpath.substr(i+3);
			i=j;
		} else
			if(tpath.substr(i, 3)==std::string(div)+"."+div)
			{
				tpath=tpath.substr(0, i)+tpath.substr(i+2);
			}
			else
				if(tpath.substr(i, 2)==std::string(div)+div)
				{
					tpath=tpath.substr(0, i)+tpath.substr(i+1);
				}
				else i++;
	}
}

using namespace std;



/*
ParamContainer::TList class implementation
*/
ParamContainer::TList::TList():tlist(new std::map<std::string, ParamContainer>)
{
}

ParamContainer::TList::~TList()
{
	delete tlist;
}

ParamContainer::TList::TList(const TList &c)
	:tlist(new std::map<std::string, ParamContainer>(*c.tlist))
{
}

ParamContainer::TList & ParamContainer::TList::operator =(const ParamContainer::TList &c)
{
	if(&c==this) return *this;
	delete tlist;
	tlist=new std::map<std::string, ParamContainer>(*c.tlist);
	return *this;
}

ParamContainer & ParamContainer::TList::operator[](std::string key)
{
	return (*tlist)[key];
}

/*
���������� ������ ParamContainer
*/

// ������������ ����� ����� ���������
const int ParamContainer::maxpnamelength=25;
// ����� ��������� �� ���������

static const char *parammessages[]=
{
	// ��������� �� �������
	"No error",
	"Parameter name length exceed",
	"Parameter name cannot contain symbols '=', '[', ']' or whitespaces",
	"Parameter already exists",
	"Abbreviation already exists",
	"Type already exists",
	"%s: invalid parameter",
	"Missing required parameter %s",
	"%s: parameter argument missing",
	"Syntax error",
	"Missing enclosing quotemark",
	"%s: invalid parameter type",
	"Missing enclosing bracket",
	"Invalid file signature",
	"%s: unable to open file",
	// ������ ���������
	"required parameter"
};
char const **ParamContainer::messages=parammessages;

ParamContainer::param ParamContainer::dumbparam=ParamContainer::param();

/*
	���������� ������ ��������� ��������� � ������
*/
ParamContainer::errcode ParamContainer::addParam(
		std::string pname, char abbr, int type,
		std::string helptopic, std::string defvalue, std::string allowedtypes)
{
	if((int)pname.length()>(int)maxpnamelength) return errParameterNameLengthExceed;
	// ������� = [] �� ����� ����������� � ����� ���������
	if((int)pname.find_first_of("= []\t")!=-1) return errParameterNameInvalid;
	if(plist.find(pname)!=plist.end()) return errDublicateParameter;
	if(abbr && alist.find(abbr)!=alist.end()) return errDublicateAbbreviation;
	param p;
	p.value=p.defvalue=defvalue;
	p.help=helptopic;
	p.pflag=type;
	p.abbr=abbr;
	p.wasset=false;
	p.allowedtypes=allowedtypes;
	plist[pname]=p;
	if(abbr) alist[abbr]=pname;
	vlist.push_back(pname);
	return errOk;
}

/*
	���������� ������ ���������� ���� ����������
*/
ParamContainer::errcode ParamContainer::addParamType(std::string tname, const ParamContainer &p)
{
	if((int)tname.find_first_of("= []\t")!=-1) return errParameterNameInvalid;
	if(tlist->find(tname)!=tlist->end()) return errDublicateType;
	tlist[tname]=p;
	tindex.push_back(tname);
	return errOk;
}


ParamContainer::errcode ParamContainer::delParam(std::string pname)
{
	std::map<std::string, param>::iterator it=plist.find(pname);
	if(it!=plist.end()) return errInvalidParameter;
	plist.erase(it);
	return errOk;
}

/*
����� �������� ����������
*/
void ParamContainer::reset(void)
{
	// �������� �� ������ ����������
	map<string, param>::iterator it;
	for(it=plist.begin(); it!=plist.end(); it++)
	{
		it->second.value=it->second.defvalue;
		it->second.wasset=false;
		if(it->second.p)
		{
			delete it->second.p;
			it->second.p=NULL;
		}
	}
}

ParamContainer::errcode ParamContainer::parseCommandLine(std::string cmdline)
{
	lastcmdline=cmdline;
	errcode err=lexicalAnalysis(cmdline);
	if(err!=errOk) return err;
	return syntaxAndSemanticsAnalysis();
}

ParamContainer::errcode ParamContainer::parseCommandLine(int argc, char *argv[])
{
	std::string s;
	for(int i=1; i<argc; i++)
		s=s+argv[i]+" ";
	return parseCommandLine(s);
}

// ����������� ������ ��������� ������ ��� ����� �������
ParamContainer::errcode ParamContainer::lexicalAnalysis(std::string s)
{
	// ������ �����������
	enum {
		normal,			// ����� �����������
		oneminus,		// ����� ������ ������
		value,			// ������ ��������� �������
		quotedvalue,	// ������ ������� � ��������
	} state=normal;
	// ��� ����������� �������
	cmdlineel::elflag flag;
	// ��������� ������� �������� ������� ����������� �������
	int startpos, pos=0;
	std::string valpart="";
	// ������� ������� ����������� ������
	lexconv.clear();
	// ������ �� ������
	int i;
	for(i=0; i<(int)s.length(); i++)
	{
		switch(state)
		{
		case normal:
			if(strchr("\t ", s[i])) continue;
			if(s[i]=='"')
			{
				flag=cmdlineel::value;
				state=quotedvalue;
				startpos=i+1;
				pos=i;
				continue;
			}
			if(s[i]=='\n')	// \n = ������, �����, �����
			{
				flag=cmdlineel::param;
				state=value;
				startpos=i+1;
				pos=i+1;
				continue;
			}
			if(s[i]=='-')
			{
				state=oneminus;
				pos=i;
				continue;
			}
			if(s[i]=='[')
			{
				lexconv.push_back(cmdlineel(cmdlineel::leftbracket, i));
				continue;
			}
			if(s[i]==']')
			{
				lexconv.push_back(cmdlineel(cmdlineel::rightbracket, i));
				continue;
			}
			if(s[i]=='=')
			{
				lexconv.push_back(cmdlineel(cmdlineel::equal, i));
				continue;
			}
			flag=cmdlineel::value;
			state=value;
			pos=startpos=i--;
			continue;
		case value:
			if(strchr("\t []=\n", s[i]))
			{
				state=normal;
				valpart+=s.substr(startpos, i-startpos);
				i--;
				lexconv.push_back(cmdlineel(flag, pos, valpart));
				valpart="";
				continue;
			}
			if(s[i]=='"')
			{
				state=quotedvalue;
				valpart+=s.substr(startpos, i-startpos);
				startpos=i+1;
				continue;
			}
			continue;
		case oneminus:
			if(strchr("\t []=\n", s[i]))
			{
				errpos=i;
				return errInvalidSyntax;
			}
			if(s[i]=='-')
			{
				flag=cmdlineel::param;
				state=value;
				startpos=i+1;
				continue;
			}
			flag=cmdlineel::abbrparam;
			state=value;
			startpos=i--;
			continue;
		case quotedvalue:
			if(s[i]=='"')
			{
				state=value;
				valpart+=s.substr(startpos, i-startpos);
				startpos=i+1;
				continue;
			}
			continue;
		}
	}
	switch(state)
	{
	case quotedvalue:
		errpos=startpos;
		return errMissingEnclosingQuotemark;
	case oneminus:
		errpos=i;
		return errInvalidSyntax;
	case value:
		valpart+=s.substr(startpos, i-startpos);
		lexconv.push_back(cmdlineel(flag, pos, valpart));
	case normal:
		break;
	}
	lexconv.push_back(cmdlineel(cmdlineel::eol, (int)lastcmdline.length()));
	return errOk;
}

// �������������� � ������������� ������ ��������� ������
ParamContainer::errcode ParamContainer::syntaxAndSemanticsAnalysis(bool fromproject)
{
	// ����� ������ ����������
	reset();
	int nonameidx=0;
	int j;
	errcode err;
	char tmp[20];
	for(int i=0; i<(int)lexconv.size(); i++)
	{
		switch(lexconv[i].flag)
		{
		case cmdlineel::value:	// ������� �������� (�� � '-')
			for(;nonameidx<(int)vlist.size() && !(plist[vlist[nonameidx]].pflag & noname);nonameidx++);
			if(nonameidx>=(int)vlist.size())
			{
				errinfo=lexconv[i].val;
				errpos=lexconv[i].pos;
				return errInvalidParameter;
			}
			err=parseComplexType(i, vlist[nonameidx], lexconv[i].val);
			if(err!=errOk) return err;
			nonameidx++;
			break;
		case cmdlineel::param:	// ������� �������� (� '--')
			if(plist.find(lexconv[i].val)==plist.end()) // ����������� ��������
			{
				if(allowunknownparams)
				{
					if(lexconv[i+1].flag==cmdlineel::equal)
					{
						i++;
						if(lexconv[i+1].flag==cmdlineel::value) i++;
					}
					break;
				}
				errinfo="--"+lexconv[i].val;
				errpos=lexconv[i].pos;
				return errInvalidParameter;
			}
			if(!fromproject && (plist[lexconv[i].val].pflag & novalue)) // � ��������� �� ������ ���� ��������
			{
				sprintf(tmp, "%04d0000", i);
				plist[lexconv[i].val].value=tmp;
				plist[lexconv[i].val].wasset=true;
				break;
			}
			if(i+1>=(int)lexconv.size() || 
				lexconv[i+1].flag!=cmdlineel::equal) // � ��������� �� ����� ��������, ���� ������ ����
			{
				errinfo="--"+lexconv[i].val;
				errpos=lexconv[i].pos;
				return errParameterArgumentMissing;
			}
			i++;
			if(i+1>=(int)lexconv.size() ||
				lexconv[i+1].flag!=cmdlineel::value) // � ��������� ������ ��������
			{
				err=parseComplexType(i, lexconv[i-1].val, "");
			} else
			{
				// ����� ����������� ��������� ��������
				i++;
				err=parseComplexType(i, lexconv[i-2].val, lexconv[i].val);
			}
			if(err!=errOk) return err;
			break;
		case cmdlineel::abbrparam:	// �������� �������� ��� ������� ����������
			for(j=0; j<(int)lexconv[i].val.length(); j++)
			{
				char c=lexconv[i].val[j];
				// ����������� ��������
				if(alist.find(c)==alist.end())
				{
					if(allowunknownparams) break;
					sprintf(tmp, "-%c", c);
					errinfo=string(tmp);
					errpos=lexconv[i].pos+j+1;
					return errInvalidParameter;
				}
				string name=alist[c];
				plist[name].wasset=true;
				if(plist[name].pflag & novalue)
				{
					// � ��������� �� ������ ���� ��������:
					// ����������� ������������� � ��������� � ��������� ����� � �������
					sprintf(tmp, "%04d%04d", i, j);
					plist[name].value=tmp;
					continue;
				}
				// �������� �������� ��������� � ����������
				if(j+1==(int)lexconv[i].val.length())
				{
					if(lexconv[i+1].flag!=cmdlineel::value) // � ��������� �� ����� ��������, ���� ������ ����
					{
						errinfo="--";errinfo[1]=c;
						errpos=lexconv[i].pos+j+1;
						return errParameterArgumentMissing;
					}
					i++;
					err=parseComplexType(i, name, lexconv[i].val);
				} else
					// �������� �������� ������ � ����������
					err=parseComplexType(i, name, lexconv[i].val.substr(j+1));
				if(err!=errOk) return err;
				break;
			}
			break;
		case cmdlineel::eol:
			break;
		default:
			errpos=lexconv[i].pos;
			return errInvalidSyntax;
		}
	}
	// ��������, ��� �� ����������� ��������� ���� ���������
	map<string, param>::iterator it;
	for(it=plist.begin(); it!=plist.end(); it++)
	{
		if((it->second.pflag & required) && !it->second.wasset)
		{
			if(it->second.pflag & noname)
				errinfo=it->first;
			else
				errinfo="--"+it->first;
			errpos=lexconv[lexconv.size()-1].pos;
			return errRequiredParameterMissing;
		}
		if(it->second.allowedtypes!="" && !it->second.wasset)
		{
			int i=0;
			err=parseComplexType(i, it->first, it->second.value);
			if(err!=errOk) return err;
		}
	}
	return errOk;
}

std::string ParamContainer::getErrCmdLine(int &pos, int maxlength) const
{
	if((int)lastcmdline.length()<=maxlength)
	{
		pos=errpos;
		return lastcmdline;
	}
	if(errpos<maxlength*2/3)
	{
		pos=errpos;
		return lastcmdline.substr(0, maxlength-3)+"...";
	}
	if((int)lastcmdline.length()-errpos<maxlength*2/3)
	{
		pos=maxlength+errpos-(int)lastcmdline.length();
		return "..."+lastcmdline.substr(lastcmdline.length()-maxlength+3);
	}
	pos=maxlength/2;
	return "..."+lastcmdline.substr(errpos-maxlength/2+3, maxlength-6)+"...";
}

// ������ ���������� ����
ParamContainer::errcode ParamContainer::parseComplexType(int &i, std::string name, std::string value)
{
	plist[name].wasset=true;
	if(plist[name].allowedtypes=="")
	{
		// �� ��������� ���
		plist[name].value=value;
		return errOk;
	}
	int pos=i+2, end=i+2, numbrackets=1;
	if(i+1<(int)lexconv.size() && lexconv[i+1].flag==cmdlineel::leftbracket)
	{
		for(i+=2; numbrackets; i++)
		{
			if(i==(int)lexconv.size())
			{
				errpos=lexconv[pos-1].pos;
				return errMissingEnclosingBracket;
			}
			if(lexconv[i].flag==cmdlineel::leftbracket) numbrackets++;
			if(lexconv[i].flag==cmdlineel::rightbracket) numbrackets--;
		}
		end=--i;
	}
	// ������������ ���
	string s="|"+plist[name].allowedtypes+"|";
	if((int)s.find("|"+value+"|")==-1)
	{
		errinfo=value;
		errpos=lexconv[pos-2].pos;
		return errInvalidType;
	}
	// �������������� ��� (��� �� �� �������� ����������?..)
	if(tlist->find(value)==tlist->end())
	{
		errinfo=value;
		errpos=lexconv[pos-2].pos;
		return errInvalidType;
	}
	plist[name].value=value;
	plist[name].p=new ParamContainer(tlist[value]);
	int j;
	for(j=pos; j<end; j++)
		plist[name].p->lexconv.push_back(lexconv[j]);
	plist[name].p->lexconv.push_back(cmdlineel(cmdlineel::eol, lexconv[pos==end?j-1:j].pos));
	errcode err=plist[name].p->syntaxAndSemanticsAnalysis();
	if(err!=errOk)
	{
		errinfo=plist[name].p->errinfo;
		errpos=plist[name].p->errpos;
	}
	return err;
}

// ������������ ��������� ������
std::string ParamContainer::getCmdLine()
{
	int minnovalue=-1, curmin=-1;
	std::string s;
	map<string, param>::iterator it, it2;
	while(1)
	{
		for(it=plist.begin(); it!=plist.end(); it++)
		{
			if((it->second.pflag & novalue) && it->second.wasset)
			{
				int val=atoi(it->second.value.c_str());
				if(val>minnovalue && (curmin==minnovalue || val<curmin))
				{
					curmin=val;
					it2=it;
				}
			}
		}
		if(curmin==minnovalue) break;
		minnovalue=curmin;
		s+="--"+it2->first+" ";
	}
	for(int i=0;i<(int)vlist.size();i++)
	{
		if(!(plist[vlist[i]].pflag & novalue) && plist[vlist[i]].wasset)
		{
			if(!(plist[vlist[i]].pflag & noname))
				s+="--"+vlist[i]+"=";
			if(plist[vlist[i]].p) s+=plist[vlist[i]].value+"["+plist[vlist[i]].p->getCmdLine()+"] ";
			else s+="\""+plist[vlist[i]].value+"\" ";
		}
	}
	s=s.substr(0, s.length()-1);
	return s;
}

ParamContainer::errcode ParamContainer::unsetParam(std::string pname)
{
	map<string, param>::iterator it=plist.find(pname);
	if(it==plist.end()) return errInvalidParameter;
	it->second.value=it->second.defvalue;
	it->second.wasset=false;
	if(it->second.p)
	{
		delete it->second.p;
		it->second.p=NULL;
	}
	return errOk;
}

/*
����� ������ ������� �� ���������
*/
void ParamContainer::printHelpTopic(FILE *f, std::string topic, int indent, int width, bool linebreak)
{
	if(!width)
	{
		fprintf(f, "%s%s", topic.c_str(), linebreak?"\n":"");
		return;
	}
	width-=indent;
	string s;
	char formatstr[10];
	sprintf(formatstr, "%%s\n%%%ds", indent);
	for(;;)
	{
		if((int)topic.length()<width)
		{
			fprintf(f, "%s%s", topic.c_str(), linebreak?"\n":"");
			return;
		}
		s=topic.substr(0, width);
		int pos = (int)s.rfind(" ");
		if(pos==-1) pos=width;
		s=s.substr(0, pos);
		topic=topic.substr(pos+1);
		fprintf(f, formatstr, s.c_str(), "");
	}
}

std::string ParamContainer::paramhelp(std::string param) const
{
	if(plist.find(param)->second.allowedtypes=="") return "<"+param+">";
	string s, t=plist.find(param)->second.allowedtypes;
	int pos=0, npos;
	while(1)
	{
		npos=(int)t.find_first_of("|", pos);
		if(npos==-1) break;
		if(tlist->find(t.substr(pos, npos-pos))->second.plist.size())
			s=s+t.substr(pos, npos-pos)+"[...]|";
		else
			s=s+t.substr(pos, npos-pos)+"|";
		pos=npos+1;
	}
	s=s+t.substr(pos);
	if(tlist->find(t.substr(pos))->second.plist.size())
		s=s+"[...]";
	return s;
}

std::string ParamContainer::typelist(std::string param) const
{
	string help=plist.find(param)->second.help;
	int tpos=(int)help.find("@types@");
	if(tpos==-1) return help;
	string s, t=plist.find(param)->second.allowedtypes;
	int pos=0, npos;
	while(1)
	{
		npos=(int)t.find_first_of("|", pos);
		if(npos==-1) break;
		s=s+t.substr(pos, npos-pos)+", ";
		pos=npos+1;
	}
	s=s+t.substr(pos);
	return help.substr(0, tpos)+s+help.substr(tpos+7);
}

/*
����� ������� � ���������� � ��������� �����
*/
void ParamContainer::dumpHelp(FILE *f, bool showparamlist, unsigned int width, std::string subtopic) const
{
	// ������ ����� ������� ��� ������ �������
	unsigned int helpindent=0;
	unsigned int l;
	// �������� �� ������ ����������
	int i;
	char s[maxpnamelength*2+10];
	unsigned int pos;
	// ����� ������ ����������
	// ������ �� 8 ������� ��� �������
	if(showparamlist)
	{
		printHelpTopic(f, helptopic.c_str(), 0, width, false);
//		fprintf(f, "%s", helptopic.c_str());
		pos = (int)(helptopic.length()-helptopic.find_last_of("\n"));
		if(subtopic!="" && plist.size())
		{
			fprintf(f, "\n        %s[", subtopic.c_str());
			pos=9+(int)subtopic.length();
		}
	}
	if(!plist.size())
	{
		showparamlist=false;
		fprintf(f, "\n");
	}
	// ������ - ���������� ���������
	for(i=0; i<(int)vlist.size(); i++)
	{
		if(plist.find(vlist[i])->second.pflag & noname)
		{
			sprintf(s, "%s ", paramhelp(vlist[i]).c_str());
			if(showparamlist)
			{
				pos += (int)strlen(s);
				if(width && (pos>width) )
				{
					pos = 8+(int)strlen(s);
					fprintf(f, "\n%8s", "");
				}
				fprintf(f, "%s", s);
			}
			l = (int)vlist[i].length()+7;
			if(l>helpindent) helpindent=l;
		}
	}
	// ����� - ������������ ���������
	for(i=0; i<(int)vlist.size(); i++)
	{
		if((plist.find(vlist[i])->second.pflag & required) && !(plist.find(vlist[i])->second.pflag & noname))
		{
			sprintf(s, "-%c %s ", plist.find(vlist[i])->second.abbr, paramhelp(vlist[i]).c_str());
			if(showparamlist)
			{
				pos += (int)strlen(s);
				if(width && (pos>width) )
				{
					pos = 8+(int)strlen(s);
					fprintf(f, "\n%8s", "");
				}
				fprintf(f, "%s", s);
			}
			l = (int)vlist[i].length()*2+7;
			if(l>helpindent) helpindent=l;
		}
	}
	// ����� ��� ���������
	for(i=0; i<(int)vlist.size(); i++)
	{
		if(plist.find(vlist[i])->second.pflag & (noname|required)) continue;
		if(plist.find(vlist[i])->second.pflag & novalue)
		{
			sprintf(s, "-%c ", plist.find(vlist[i])->second.abbr);
			l=(int)vlist[i].length();
		} else
		{
			sprintf(s, "-%c %s ", plist.find(vlist[i])->second.abbr, paramhelp(vlist[i]).c_str());
			l=(int)vlist[i].length()*2+7;
		}
		if(showparamlist)
		{
			pos += (int)strlen(s);
			if(width && (pos>width) )
			{
				pos = 8+(int)strlen(s);
				fprintf(f, "\n%8s", "");
			}
			fprintf(f, "%s", s);
		}
		if(l>helpindent) helpindent = l;
	}
	if(showparamlist)
	{
		if(subtopic!="") fprintf(f, "\b]\n");
		else fprintf(f, "\n\n");
	}
	// ���������� ������� ���������
	char formatstr[10];
	sprintf(formatstr, "%%-%ds", helpindent);
	if(width<(helpindent+20)) width = helpindent+20;
	for(i=0; i<(int)vlist.size(); i++)
	{
		if(plist.find(vlist[i])->second.pflag & noname)
		{
			fprintf(f, " %c     ", plist.find(vlist[i])->second.pflag & required?'*':' ');
		//	sprintf(s, "<%s> ", vlist[i].c_str(), vlist[i].c_str());
			sprintf(s, "<%s> ", vlist[i].c_str());
			fprintf(f, formatstr, s);
			printHelpTopic(f, typelist(vlist[i]), helpindent+7, width);
		}
	}
	for(i=0; i<(int)vlist.size(); i++)
	{
		if((plist.find(vlist[i])->second.pflag & required) && !(plist.find(vlist[i])->second.pflag & noname))
		{
			if(plist.find(vlist[i])->second.abbr)
				fprintf(f, " * -%c, ", plist.find(vlist[i])->second.abbr);
			else
				fprintf(f, " *     ");
			sprintf(s, "--%s=<%s> ", vlist[i].c_str(), vlist[i].c_str());
			fprintf(f, formatstr, s);
			printHelpTopic(f, typelist(vlist[i]), helpindent+7, width);
		}
	}
	for(i=0; i<(int)vlist.size(); i++)
	{
		if(plist.find(vlist[i])->second.pflag & (noname|required)) continue;
		if(plist.find(vlist[i])->second.abbr)
			fprintf(f, "   -%c, ", plist.find(vlist[i])->second.abbr);
		else
			fprintf(f, "       ");
		if(plist.find(vlist[i])->second.pflag & novalue)
			sprintf(s, "--%s ", vlist[i].c_str());
		else
			sprintf(s, "--%s=<%s> ", vlist[i].c_str(), vlist[i].c_str());
		fprintf(f, formatstr, s);
		printHelpTopic(f, typelist(vlist[i]), helpindent+7, width);
	}
	fprintf(f, "\n");
	if(dumpsubparamhelp)
	{
		for(i=0; i<(int)tindex.size(); i++)
			tlist->find(tindex[i])->second.dumpHelp(f, true, width, tlist->find(tindex[i])->first);
	}
	if(subtopic=="")
	{
		fprintf(f, " * = %s\n", messages[msgRequiredParameter]);
	}
}

/*
	����� ������ ���������� � ������������ �� ����������
*/
void ParamContainer::saveParams(FILE *f, std::string signature) const
{
	if(signature!="") fprintf(f, "[%s]\n", signature.c_str());
	// �������� �� ������ ����������
	map<string, param>::const_iterator it;
	for(it=plist.begin(); it!=plist.end(); it++)
	{
		if(it->second.pflag & novalue)
		{
			if(it->second.wasset) fprintf(f, "%s=%s\n", it->first.c_str(), it->second.value.c_str());
		}
		else
		{
			if(it->second.p)
				fprintf(f, "%s=%s[%s]\n", it->first.c_str(), it->second.value.c_str(), it->second.p->getCmdLine().c_str());
			else
				if(it->second.wasset) 
					fprintf(f, "%s=\"%s\"\n", it->first.c_str(), it->second.value.c_str());
		}
	}
}

/*
���������� ����� �������
*/
ParamContainer::errcode ParamContainer::saveParams(std::string filename, std::string signature)
{
	lastcmdline="";
	errpos=0;
	errinfo=filename;
	FILE *f=fopen(filename.c_str(), "wt");
	if(!f) return errUnableToOpenFile;
	char cwd[1024];
	getcwd(cwd, 1024);
	strcat(cwd, cwd[0]=='/'?"/":"\\");
	relToAbsPath(cwd, filename);
	convertFilePaths(cwd, filename);
	saveParams(f, signature);
	fclose(f);
	return errOk;
}

/*
��������� ��������� �� ����� ������� � ��������������� ��� ������ � ����������
*/
ParamContainer::errcode ParamContainer::loadParams(std::string filename, std::string signature)
{
	lastcmdline="";
	errpos=0;
	errinfo=filename;
	FILE *f=fopen(filename.c_str(), "rt");
	if(!f) return errUnableToOpenFile;
	errcode err=loadParams(f, signature);
	fclose(f);
	if(err!=errOk) return err;
	char cwd[1024];
	getcwd(cwd, 1024);
	strcat(cwd, cwd[0]=='/'?"/":"\\");
	relToAbsPath(cwd, filename);
	convertFilePaths(filename, "");
	return errOk;
}

/*
��������� ��������� �� ����� �������
*/
ParamContainer::errcode ParamContainer::loadParams(FILE *f, std::string signature)
{
	int i=0;
	char str[1024];
	string s;
	if(signature!="")
	{
		fgets(str, 1024, f);
		if(!*str) return errInvalidSignature;
		if(str[strlen(str)-1]=='\n') str[strlen(str)-1]=0;
		s=str;
		if(s!="["+signature+"]") return errInvalidSignature;
	}
	// ����� ������ ����������
	reset();
	s="";
	while(!feof(f))
	{
		// ������ �� ������� �� �����
		i++;
		*str=0;
		fgets(str, 1024, f);
		if(str[strlen(str)-1]=='\n') str[strlen(str)-1]=0;
		if(!str[0]) continue;
		s=s+"--"+str+" ";
		if(s.length()>1048576)
			return errInvalidSyntax;
	}
	lastcmdline=s;
	errcode err=lexicalAnalysis(s);
	if(err!=errOk) return err;
	return syntaxAndSemanticsAnalysis(true);
}

void ParamContainer::convertFilePaths(std::string dirfrom, std::string dirto)
{
	// �������� �� ������ ����������
	map<string, param>::iterator it;
	for(it=plist.begin(); it!=plist.end(); it++)
	{
		if((it->second.pflag & filename) && it->second.value!="")
		{
			// �������� - �������� ��� ����� - �����������
			relToAbsPath(dirfrom, it->second.value);
			absToRelPath(dirto, it->second.value);
		}
		if(it->second.p)
		{
			// ��������� �� �� ����� ��� ��������� ParamContainer
			it->second.p->convertFilePaths(dirfrom, dirto);
		}
	}
}
