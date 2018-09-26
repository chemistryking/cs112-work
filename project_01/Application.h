/* Header for the application class.
 * application.h
 *
 *  Created on: Sep 17, 2016
 *      Author: Matthew Nykamp
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "PlayList.h"
#include <string>

class Application {
public:
	Application(const string&);
	void start();
private:
	bool isRunning;
	string file;
};



#endif /* APPLICATION_H_ */
