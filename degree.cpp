#include <iostream>
#include <fstream>

using namespace std;  

//*************Useful functions************************************.
//getNumberOfRecords receives a c string with the filename/fullpath
// returns the number of lines/rows, and -1 if error
int getNumberOfRecords(char fn[]) {
	ifstream input;

	input.open(fn);

	if (!input.is_open())
		return -1; 

	int counter = 0;
	
	char buffer[1000] = { '\0' };

	
	while (!input.eof()) {
		
		input.getline(buffer, sizeof(buffer));
		
		counter++;
	}
	
	input.close();
	
	return counter;
}


//getStringLength receives a valid c string.
// return the number of characters, not including the '\0'
int getStringLength(const char* str) {
	//initialize a counter
	int i = 0;
	//Execute the loop-body till the '\0' is found
	while (str[++i] != '\0'); //<-- notice the pre increment on i and ;
	//Once the loop is done, return the value in i
	return i;
}

//copyString receives two c strings:
// const char * src: the source/original c string. 
//                   const is used so it can accept c string literals
// char *& dst: the destination c string. 
//				a modifiable (&) c string (char *)
void copyString(const char* src, char*& dst) {
	//First determine the length of the src
	int len = getStringLength(src);
	//Dynamically allocate memory for the dst.
	// Remember: the length does not include the '\0'
	dst = new char[len + 1];
	//Go through all the elements of the src, till '\0' is found
	int i = 0;
	while (src[i] != '\0') {
		//At each step, create a copy of src[i] into dst[i]
		dst[i] = src[i];
		//Move to the next element
		i++;
	}
	//Do not forget to add the string termination character in the 
	//dst c string
	dst[i] = '\0';
}

/***********************************************************************/
//Write here your code to define the enumerators, structures, and any 
// function you may need.
enum PREFIX_VALUES  {MATH, CS, RHET, ECS, PHYS, GOVT};
enum SEMESTER_VALUES {FALL, SPRING, SUMMER};

struct degree_plan_details {
    int credit_hour;
    int number;
    PREFIX_VALUES pv; 
    char* title; 
    int prefix_num;
};

struct transcript_details {
    PREFIX_VALUES pv;
    int number;
    SEMESTER_VALUES sv;
    int year;
    int prefix_num;
    int semester_num;
};

typedef struct degree_plan_details course;
typedef struct transcript_details course_taken;

int readDegreePlan(char filename[], course*& degree_plan_array, int){
    ifstream input;
    input.open(filename);
    if(!input.is_open())
    return -2;

    int counter = 0;
    char helper[1000];
    while (!input.eof()){
        
        input >> degree_plan_array[counter].prefix_num;
        input >> degree_plan_array[counter].number;
        input >> degree_plan_array[counter].credit_hour;

        input.getline(helper, sizeof(helper));
        degree_plan_array[counter].title = nullptr;
        copyString(helper, degree_plan_array[counter].title);

            if(degree_plan_array[counter].prefix_num == 100){
            degree_plan_array[counter].pv = MATH;
        }
               else if(degree_plan_array[counter].prefix_num == 150){
            degree_plan_array[counter].pv = CS;
        }
               else if(degree_plan_array[counter].prefix_num == 400){
            degree_plan_array[counter].pv = RHET;
        }
               else if(degree_plan_array[counter].prefix_num == 450){
            degree_plan_array[counter].pv = ECS;
        }
               else if(degree_plan_array[counter].prefix_num == 500){
            degree_plan_array[counter].pv = PHYS;
        }
               else if(degree_plan_array[counter].prefix_num == 1000){
            degree_plan_array[counter].pv = GOVT;
        }
counter++;
    }
input.close();
return counter;
}

int readTranscript(char filename[], course_taken*& transcript, int){
 ifstream input;
    input.open(filename);
    if(!input.is_open())
    return -3;

    int counter = 0;
    char helper[1000];
    while (!input.eof()){
        input >> transcript[counter].prefix_num;
        input >> transcript[counter].number;
        input >> transcript[counter].semester_num;
        input >> transcript[counter].year;

                    if(transcript[counter].prefix_num == 100){
            transcript[counter].pv = MATH;
        }
               else if(transcript[counter].prefix_num == 150){
            transcript[counter].pv = CS;
        }
               else if(transcript[counter].prefix_num == 400){
            transcript[counter].pv = RHET;
        }
               else if(transcript[counter].prefix_num == 450){
            transcript[counter].pv = ECS;
        }
               else if(transcript[counter].prefix_num == 500){
            transcript[counter].pv = PHYS;
        }
               else if(transcript[counter].prefix_num == 1000){
            transcript[counter].pv = GOVT;
        }

        if(transcript[counter].semester_num == 0){
            transcript[counter].sv = FALL;
        }
               else if(transcript[counter].semester_num == 1){
            transcript[counter].sv = SPRING;
        }
               else if(transcript[counter].semester_num == 2){
            transcript[counter].sv = SUMMER;
        }
        counter++;
    }
    input.close();
    return counter;
}

int coursesTakenPerYear(course_taken* transcript, int size, int r){
   int counter = 0;
    for(int i = 0; i < size; i++){
        if(transcript[i].year != r){
            continue;
        }
            else if(transcript[i].year = r)
            counter++;
            continue;
        }
        return counter;
    }

int earnedCreditsPerSemester(course_taken* transcript, int size1, course* degree_plan_array, int size2, SEMESTER_VALUES sem, int year){
int counter = 0;
        for(int i = 0; i < size1; i++){
            if(transcript[i].semester_num != sem && transcript[i].year != year){
                continue;
            }
            else if(transcript[i].semester_num == sem && transcript[i].year == year)
            {
                for(int j = 0; j < size2; j++){
                   counter + degree_plan_array[j].credit_hour;
                   continue;
                }
            }
        }
        return counter;
}

int main() {
    //************************* [PART 1] ****************************************//
    //The degree plan is stored in a text file, named degree_plan.txt;
    char degree_plan_filename[] = "degree_plan.txt";
    
    //Step 1.1) Count the number of lines in the input file.
    int degree_plan_size = getNumberOfRecords(degree_plan_filename);
    
    //test the returned value
    if (degree_plan_size <= 0)
        return degree_plan_size;

    //Step 1.2) dynamically allocate an array of course structures
    course* degree_plan_array = new course[degree_plan_size];
    
    //Step 1.3) read the information in degree_plan.txt into degree_plan dynamic array
    int ret_value = readDegreePlan(degree_plan_filename, degree_plan_array, degree_plan_size);
    //test the returned value
    if (ret_value <= 0)
        return ret_value;

    //To test part 1, let's count the number of credit hours in the degree plan
    int total = 0;
    for (int i = 0; i < degree_plan_size; i++) {
        total += degree_plan_array[i].credit_hour;
    }
    //Print on the screen 
    cout << total << endl;
    //************************* [END OF PART 1] ****************************************//
    //************************* [PART 2] ****************************************//
    //The transcript is stored in a text file, named transcript.txt;
    char transcript_filename[] = "transcript.txt";

    //Step 2.1) Count the number of lines in the input file.
    int transcript_size = getNumberOfRecords(transcript_filename);

    //test the returned value
    if (transcript_size <= 0)
        return transcript_size;

    //Step 2.2) dynamically allocate an array of course structures
    course_taken* transcript = new course_taken[transcript_size];

    //Step 2.3) read the information in transcript.txt into transcript dynamic array
    int ret_value_t = readTranscript( transcript_filename, transcript, transcript_size);
    //test the returned value
    if (ret_value_t <= 0)
        return ret_value_t;

    //To test part 2, let's count the number of courses taken in 2022
    int courses_taken_per_year = coursesTakenPerYear(transcript, transcript_size, 2022);

    //Print on the screen 
    cout << courses_taken_per_year  << endl;
    //************************* [END OF PART 2] ****************************************//

    //************************* [PART 3] ****************************************//
    //This part combines part 1 and 2.
    int earned_credits_per_semester = earnedCreditsPerSemester(transcript, transcript_size, degree_plan_array, degree_plan_size, SPRING, 2022);
    cout << earned_credits_per_semester << endl;
    //************************* [END OF PART 3] ****************************************//
    return 0;
}//End of main