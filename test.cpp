#include <stdio.h>
#include <string.h>
 struct ManagerStudent
 {
 		char student_list[100][50]; 
 		int Num =0;
 	void add(const char* kStudent_name) /*Add to Array*/
	 {  
 		if (Num > 100)
		 {
 			printf("The list has full. It cannot add a new student.s\n");
 		}
		 	strcpy(student_list[Num],kStudent_name);
		 	Num++;
		 	printf("Student has been added to list successfully!\n");
		}	
	void search(const char* kStudent_name)
	{
		int length = strlen(kStudent_name);
	  	int k=0;
	  	int n; 
	  	int get_student;
	  	for (int i=0; i < Num; i++)
	  {
	  	int length_search = strlen(student_list[i]);
	  	if (length == length_search)
	  		{	
	  			get_student = 1;
	  			for(int j =0;j < length; j++)
	  			{
	  				if(student_list[i][j] != kStudent_name[j])
					{
					get_student = 0; 
					break;
					}
				}
				if (get_student == 1)
		  {
		  	k++;
		  	n=i;
		  }
	  		
	  	}
	  }
	  	if(k==0)
		  {
		  	printf("Student name is not existed\n");
		  }	else if(k == 1) printf("Number of student: %d\n",n);
	}
	void remove(const char* kStudent_name)
	{
		int length = strlen(kStudent_name);
	  	int k=0;
	  	int n; 
	  	int get_student;
	  	for (int i=0; i < Num; i++)
	  {
	  	int length_search = strlen(student_list[i]);
	  	if (length == length_search)
	  		{	
	  			get_student = 1;
	  			for(int j =0;j < length; j++)
	  			{
	  				if(student_list[i][j] != kStudent_name[j])
					{
					get_student = 0; 
					break;
					}
				}
				if (get_student == 1)
		  {
		  	k++;
		  	n=i;
		  }
	  		
	  	}
	  }if(k==0)
		  {
		  	printf("Student name is not existed\n");
		  }	
		if(k == 1)
		{
	  		strcpy(student_list[n], student_list[Num-1]);
	  		Num--;
	  		printf("This name has been removed from list successfully!\n");
		}
	  
	}

	void sort(){
		int i, j;
		char t[50];
		for (i = 1; i < Num; i++) {
		 for (j = 1; j < Num; j++) {
         if (strcmp(student_list[j - 1], student_list[j]) > 0) {
            strcpy(t, student_list[j - 1]);
            strcpy(student_list[j - 1], student_list[j]);
            strcpy(student_list[j], t);
         }
      }
	}
}
	void display()
	{	printf(".............................\n");
		for (int i = 0; i < Num; i++)
		 {printf("%d| %s\n", i, student_list[i]);}
		printf(".............................\n");
	 }

};
 int main(){
 	ManagerStudent list;
 	int choice;
	while(true){
		printf("1. Add a student name into the list.\n");
        printf("2. Search a student name.\n");
        printf("3. Remove a student name.\n");
        printf("4. Show the list of students in alphabetical order.\n");
        printf("5. Exit the program.\n");
        printf("\nEnter choice(1-5) : ");
		scanf("%d", &choice);
        switch (choice){
        	char name[30];
        	case 1:
        		printf("Enter name to add: ");
        		scanf("%s",name);
        		list.add(name);
        		list.display();
        		break;
        	case 2:
        		printf("Enter name to search: ");
        		scanf("%s",name);
        		list.search(name);
        		break;
        	case 3:
        		printf("Enter name to delete: ");
        		scanf("%s",name);
        		list.remove(name);
        		list.display();
        		break;
			case 4:
				list.sort();
				list.display();
        		break;
		
			case 5:
				break;
			default: break;
		}
		if(choice == 5) break;
	}
 
 
  return 0;
 }
