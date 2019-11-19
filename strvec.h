// Name: Chase Keller
// Date: 10/8/19
// Purpose: This is my H file which has all of my prototypes for my strvec.c and my main.c file

#ifndef STRVEC_H
#define STRVEC_H

typedef struct strvec {

	char ** starr;
	int num_elements;
	int capacity;

	// put your member "variables" here
} strvec;

	void strvec_init(strvec * svec);	//Initialize my string vector.
	void strvec_free(strvec * svec);	//Free memory used by the string vector
	void strvec_push(strvec * svec, const char* str);	//Adds things onto the string vector (array)
	char* strvec_get(const strvec svec, int idx);		//gets the string at a certain index
	int strvec_size(const strvec svec);		//get the size of the vector
	int strvec_capacity(const strvec svec);	//get the current number stored into the vector

	void prompt();	//prints the new prompt
	void read_cmd(strvec * cmd);	//reads the input from the user
	void exec_cmd(const strvec * cmd);	//print the input that is now stored into the vector


#endif