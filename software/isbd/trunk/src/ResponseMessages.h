#ifndef CONST_MESSAGES_H
#define CONST_MESSAGES_H

#define OK_WELCOME 			"Welcome"
#define OK_CLOSE_CONNECTION		"Closing connection"
#define OK_START_AUTH 			"Starting authorization sequence"
#define OK_USER_ACCEPTED        	"Username accepted, password needed"
#define OK_USER_LOGIN_SUCCESS   	"User logged in successfully"
#define OK_FLUSHING			"Flushing Bytes from buffer"
#define OK_NO_DATA			"No data waiting in buffer"
#define OK_GOING_DOWN			"Server is going down"
#define OK_COMMAND_MODE			"Entering Command Mode"
#define OK_HELP				"Help"



#define ERR_AUTH_TYPE_REQUIRED		"AUTH type needed"
#define ERR_USER_NEEDED			"USER needed"
#define ERR_MAX_AUTH_TRIES		"Maximum number of authentication tries exceeded"
#define ERR_PASSWORD_INCORRECT		"Password incorrect. Please try again"
#define ERR_INVALID_COMMAND		"Unrecognized command. Type HELP for a list of available commands"
#define ERR_BUFFER_OVERRUN		"Buffer overrun occured"

//prefixes
#define RESP_OK 			"+OK"
#define RESP_ERR 			"+ERR"

#endif
