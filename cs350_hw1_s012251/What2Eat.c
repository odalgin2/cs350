#include <stdio.h>
#include <stdbool.h>
int main(){
	
	printf("First Round \n");
	printf("How many people are there : ");
	int people;
	scanf("%d", &people);
	int threshold = 3*people + 3;
	printf("The threshold value is %d -> (Total point of a food needs to exceed that boundary.)\n", threshold);
	int input;
	
	int points[5];
	int shortList[5];
	
	char foodListSelect[5][20] = {"1-Kebab", "2-Burger", "3-Pasta", "4-Lahmacun", "5-Salad"};
	char foodListSelected[5][20] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
	
	printf("Here is the menu. To select food, you should write its number.\n");
	for(int i=0; i<people; i++)
	{
		printf(" 1-Kebab\n 2-Burger\n 3-Pasta\n 4-Lahmacun\n 5-Salad\n");
		printf("Person-%d:\n",(i+1));
		for(int j=5; j>0; j--)
		{
			printf("Your %d. preference is : ", (5-j+1));
			scanf("%d", &input);
			points[input-1] += j;
		}
	}
	
	for(int i=0; i<5; i++)
		printf("%s = %d point\n", foodListSelected[i],points[i]);
		
	for(int i=0; i<5; i++)
		shortList[i] = points[i];
		
		
	for(int i=0; i<5; i++)
	{
		if(points[i]<threshold)
			shortList[i]=0;
	
	}
	
	bool temp = true;
	int tempSize = 0;
	int tempIndex = -1;
	
	for(int i=0; i<5; i++)
	{
		if(shortList[i] !=0)
		{
			puts(foodListSelect[i]);
			temp = false;
			tempSize = tempSize + 1;
		}
	}
	int finalShortList[5];
	for(int i=0; i<5; i++)
		finalShortList[i] = 0;
	
	if(temp)
		printf("You are eating at home/dorm today!\n");
	else{
		if(tempSize == 1){
			for(int i=0; i<5; i++){
				if(shortList[i] != 0)
					tempIndex = i;
				
					
			}
			printf("You are eating %s today!\n", foodListSelected[tempIndex]);
			return 0;
		}
		
		printf("Second Round.\nSelect food from the list which are above from the threshold: \n");
		
		for(int i=0; i<people; i++)
		{
		
		  printf("Person-%d:\n",(i+1));
		  for(int j=tempSize; j>0; j--)
		  {
			printf("Your %d. preference is : ", (tempSize-j+1));
			scanf("%d", &input);
			finalShortList[input-1] += j;
		  }
		}
		int k = 0;
		int max2 = finalShortList[k];
		for (int i=0; i<5; i++){
			if(finalShortList[i] > max2){
				max2 = finalShortList[i];
				k = i;
			}
		}
		for(int i=0; i<5; i++){
			if(finalShortList[i] != 0)
				printf("%s gets %d points.\n", foodListSelected[i],finalShortList[i]);
			}
		printf("You are eating %s today!\n", foodListSelected[k]);
	}
	
	
	return 0;
}
