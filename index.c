#include<stdio.h>
#include<string.h>

// function to locate the positions for text and pattern character
void makeLinearMap(int *map, int dim, int offset);

// function to draw rows of the pattern
void drawBlock(int dim, int *map, char *name, char *pattern);

int main() {
	
	// intitiate
	printf("\n  Welcome To Texta!\n\n");
	
	// get name
	char name[255];
		// capture
		printf("  What's your first name?\n  >> ");
		scanf("%s", &name);
	
	// get pattern
	char pattern[2];
		// capture
		printf("\n  Choose texture character: e.g * - # $ ^ \n  >> ");
		scanf("%s", &pattern);
	
	// length of name
	int nameLen = strlen(name);
	
	// the block
		// offset from the left
		int offset = (nameLen/2) + 2;
		
		// dimensions
		int dim = nameLen + (offset*2);
		
		// map of the name block
		int map[dim] = { 0 };
			// build block
			makeLinearMap(map, dim, offset);
	
	// displace downwards
	printf("\n\n\n\n");
	
	// draw block
	drawBlock(dim, map, name, pattern);
	
	// displace downwards
	printf("\n\n\n\n");
	
	return 0;
}

// function to locate the positions for text and pattern character
void makeLinearMap(int *map, int dim, int offset) {
	// left & right limits
	int liml = offset,
		limr = dim - offset;
	// map iterator
	int j = 1;
	// block builder
	for(int i = 0; i < dim; i++)
	{
		if(i >= liml && i < limr)
		{
			map[i] = j;
			j++;
			continue;
		}
		map[i] = 0;
	}
}

void drawBlock(int dim, int *map, char *name, char *pattern) {
	// row builder
	for(int j = 0; j < dim; j++){
		// block offset from left part of screen
		printf("%10s"," ");
		// column builder
		for(int i = 0; i < dim; i++) 
		{
			// locate positon and put
			if(j == (dim%2 + dim/2 - 1) && map[i] != 0)
			{
				printf(" %c ", name[map[i-1]]);	
			}
			else 
			{
				printf(" %c ", pattern[0]);
			}	
		}
		printf("\n");
	}
}
