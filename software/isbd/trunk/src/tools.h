#ifndef TOOLS_H_
#define TOOLS_H_
//	void *start_thread(void*);
	void check_required_params(void);
	void daemonize(void);
	void waitforchild(void);
	void handle_sigint(int);
	void handle_sighup(int);
#endif /*TOOLS_H_*/
