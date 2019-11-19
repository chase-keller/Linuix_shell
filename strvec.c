// Name: Chase Keller
// Date: 10/8/19
// Purpose: This file has my funtions setting up my string vector and the functions assosiated to that Project 1

#include <stdio.h>
#include <stdlib.h>
#include "strvec.h"
#include <string.h>

	void strvec_init(strvec * svec){
		//sets capacity to 4
		svec->capacity = 4;
		//sets size to zero since it is empty
		svec->num_elements = 0;
		//Sets capacity to 4 characters since capacity is set to 4
		svec->starr = (char**)calloc(svec->capacity, sizeof(char*));
	}

	void strvec_free(strvec * svec){
		//looks to see if the array pointer is null
		
			//if not it goes through and frees each index
			int i = 0;
			while(svec->starr&& svec->starr[i]){
			//for(int i = 0; i < svec->num_elements; i++){
				free (svec->starr[i]);
				i++;
			}
			//Frees and sets everything back to the original values
			free(svec->starr);
			svec->starr = NULL;
			svec->capacity = 0;
			svec->num_elements = 0;
		
	}

	void strvec_push(strvec * svec, const char* str){
		//Checks to see if the num of elements is at or greater than capacity
		if(svec->num_elements >= svec->capacity - 1){

			if(svec->capacity == 0){
				svec->capacity = 2;
			}
		//Sets capacity to double becasue realloc doubles capacity
		svec->capacity *= 2;
		//Doubles the amount of space in the array
		svec->starr = (char**)realloc(svec->starr, svec->capacity * sizeof(char*));

		}
		//Sets the size in the index to the size of string + 1
		svec->starr[svec->num_elements] = (char*)calloc(strlen(str) + 1, sizeof(char));
		//Copies String from str to index num_elements
		strcpy(svec->starr[svec->num_elements], str);
		//adds one to size due to the new str being added
		svec->num_elements += 1;
		//after the increment sets the new last value to NULL
		svec->starr[svec->num_elements] = NULL;
	}
	//Gets the array at a certain index and if nothing is there it returns NULL
	char* strvec_get(const strvec svec, int idx){
	    if(idx < 0 || idx >= svec.num_elements)
        	return NULL;
    
    	return svec.starr[idx];
	}
	//returns the size of the array
	int strvec_size(const strvec svec){
		return svec.num_elements;
		}
	//returns how size of memeory that is in the array
	int strvec_capacity(const strvec svec){
		return svec.capacity;
		}

