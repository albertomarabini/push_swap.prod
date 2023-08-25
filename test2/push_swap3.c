#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (-1);
	}
	else if (s2 == NULL)
		return (1);
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (s == NULL)
		return (NULL);
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		size = 1;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}

// int* createArray(int n) {
//     int* arr = malloc(n * sizeof(int));
//     if (arr == NULL) {
//         return NULL;
//     }
// void createArray(int *arr, int n) {
//     srand(time(NULL));
//     int half = n / 2;
//     int* values = malloc(n * sizeof(int));
//     if (values == NULL) {
//         printf("Failed to allocate memory for the values array.\n");
//         free(arr);
//         return NULL;
//     }

//     for (int i = 0; i < n; i++) {
//         values[i] = i - half;
//     }

//     for (int i = 0; i < n; i++) {
//         int randomIndex = rand() % n;
//         int temp = values[i];
//         values[i] = values[randomIndex];
//         values[randomIndex] = temp;
//     }

//     for (int i = 0; i < n; i++) {
//         *arr[i] = values[i];
//     }

//     free(values);
// }
// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	int	*numbers;

// 	int argc - 1;
// 	i = 0;
// 	if (argc < 2)
// 		return (1);
// 	numbers = (int *)malloc((argc - 1) * sizeof(int));
// 	if (numbers == NULL)
// 		return (1);
// 	while (i < argc - 1)
// 		numbers[i] = atoi(argv[i + 1]);
// 	free(numbers);
// 	return (0);
// }




#define STACK_SIZE 15


int findSmallest(int a, int b) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    return smallest;
}

int bigger(int a, int b)
{
	return (a > b);
}
int	smaller(int a, int b)
{
	return (a < b);
}
int	isSorted(int arr[], int size, int bottom, int (*f)(int a, int b))
{
	for (int i = bottom; i < size - 1; i++)
	{
		if (f(arr[i + 1], arr[i]))
		{
			return (i);
		}
	}
	return (size - 1);
}
char *swap(int *a, int *b, char id)
{
	int	temp;
	char *ret;

	ret = ft_strnew(2);
	temp = *a;
	*a = *b;
	*b = temp;
	ret[0] = 'r';
	ret[1] = id;
	return ret;
}
char *rotateLeft(int *stack, int length, int bottom, char id)
{
	int	temp;
	char *ret;

	ret = ft_strnew(2);
	temp = stack[bottom];
	for (int i = bottom; i < length-1 ; i++)
	{
		stack[i] = stack[i + 1];
	}
	stack[length-1] = temp;
	ret[0] = 'r';
	ret[1] = id;
	return ret;
}

char *rotateRight(int *stack, int length, int bottom, char id)
{
	int	temp;
	char *ret;

	ret = ft_strnew(3);
	temp = stack[length-1];
	for (int i = length-1; i > bottom; i--)
	{
		stack[i] = stack[i - 1];
	}
	stack[bottom] = temp;
	ret[0] = 'r';
	ret[1] = 'r';
	ret[2] = id;
	return ret;
}
void printArrays(int sortedStack[], int stackA[], int stackB[], int topMap, int lstackA, int bottomMap, int lstackB, int bottomB, int length, int lTrapB[]) {
	printf("%*s|%*s\n", (bottomMap +1) * 3 + 11, "bottomMap", (topMap - bottomMap + 2) * 3, "|topMap");
    printf("sortedStack: ");
    for (int i = 0; i < length; i++) {
        printf("%2d ", sortedStack[i]);
    }
    printf("\n");


	printf("%*s|\n", (lstackA)  * 3 + 11, "lstackA");
    printf("stack A    : ");
    for (int i = 0; i < length; i++) {
        printf("%2d ", stackA[i]);
    }
    printf("\n");
    printf("stack B    : ");
    for (int i = 0; i < length; i++) {
        printf("%2d ", stackB[i]);
    }
    printf("\n");
    printf("%*s|\n", (lstackB)  * 3 + 11, "lstackB");
    printf("\n");
    printf("ltrapB     : ");
    for (int i = 0; i < length; i++) {
        printf("%2d ", lTrapB[i]);
    }
	printf("\n");
}

int findElement(int* arr, int n, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return -1; // Element not found
}
int	main(void)
{
	int	sortedStack[STACK_SIZE];
	for (int i = 0; i < STACK_SIZE; i++) {
        sortedStack[i] = i;
    }
	srand(time(NULL));
    for (int i = 0; i < STACK_SIZE; i++) {
        int randomIndex = rand() % STACK_SIZE;
        int temp = sortedStack[i];
        sortedStack[i] = sortedStack[randomIndex];
        sortedStack[randomIndex] = temp;
    }
	int	currentIndex;
	int	topElement;
	int	rotationCount;

	int	stackA[STACK_SIZE];
	int	i;
	// Example input numbers
	int stackB[STACK_SIZE] = {}; // Empty stack B
	int lTrapB[STACK_SIZE] = {}; // Empty left trap B array
	for (int i = 0; i < STACK_SIZE; i++)
	{
		stackA[i] = sortedStack[i] ;
	}
	// Bubble sort stack A and void lTrapB
	for (int i = 0; i < STACK_SIZE - 1; i++)
	{
		lTrapB[i] = 0;
		for (int j = 0; j < STACK_SIZE - i - 1; j++)
		{
			if (sortedStack[j] > sortedStack[j + 1])
			{
				free(swap(&sortedStack[j], &sortedStack[j + 1],' '));
			}
		}
	}
	int lstackA = STACK_SIZE;
	int lstackB = 0;
	int bottomMap = STACK_SIZE/2 - 1;//<----
	//int midMap = STACK_SIZE/2 + 1;
	//int topMap = STACK_SIZE-1;
	int topMap = STACK_SIZE/2;
	int bottomB = 0;
	currentIndex = 0;
	int totalMoves = 0;
	char *moveA = NULL;
	char *moveB = NULL;
	int rTrapB = 0;
	int nextMove =0;

	while (1)
	{
		// int	nPosMidRight = findElement(stackA, sortedStack[midMapRight], lstackA + 1);
		// int nPosMidLeft = findElement(stackA, sortedStack[midMapLeft], lstackA + 1);
		int nPosBottom = findElement(stackA, sortedStack[bottomMap], lstackA);
		int nPosUpper = findElement(stackA, sortedStack[topMap], lstackA);
		int nPosMinra= findSmallest(nPosBottom,nPosUpper);
		int nPosMinrra =findSmallest(lstackA - nPosBottom,lstackA - nPosUpper-1);
		// int nPosMinra= findSmallest(nPosMidRight,nPosMidLeft,nPosBottom,nPosUpper);
		// int nPosMinrra =findSmallest(lstackA - nPosMidRight, lstackA - nPosMidLeft,lstackA - nPosBottom,lstackA - nPosUpper);
		char *nextOp;
		if(nPosMinra< nPosMinrra)
			nextOp = "ra";
		else
			nextOp = "rra";
		if (stackA[lstackA-1] == sortedStack[bottomMap])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA-1];
			bottomMap--;
			lstackA--;
			lstackB++;
			if (stackB[0] == sortedStack[bottomMap])
			{
				rotateLeft(stackB, lstackB, 0,'b');
				totalMoves++;
				swap(&stackB[lstackB-1], &stackB[lstackB -2],'b');
				totalMoves++;
				moveB = "sb";
				rotateRight(stackB, lstackB, 0,'b');
				totalMoves++;
				bottomMap--;
			}
			rotateRight(stackB, lstackB, 0,'b');
			totalMoves++;
			moveB = "rb";
		}
		else if (topMap <= STACK_SIZE-1 && stackA[lstackA-1] == sortedStack[topMap])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA-1];
			if (lstackB>0 && stackB[lstackB] < stackB[lstackB - 1])
			{
				swap(&stackB[lstackB], &stackB[lstackB -1],'b');
				totalMoves++;
				moveB = "sb";
				topMap++;
			}
			lstackA--;
			lstackB++;
			if (lstackB>2 && stackB[lstackB-2] < stackB[lstackB - 3])
			{
				rotateRight(stackB, lstackB, 0,'b');
				totalMoves++;
				swap(&stackB[lstackB-2], &stackB[lstackB -1],'b');
				totalMoves++;
				moveB = "sb";
				rotateLeft(stackB, lstackB, 0,'b');
				totalMoves++;
				topMap++;
			}
			topMap++;
		}
		else if (topMap < STACK_SIZE-1 && stackA[lstackA-1] == sortedStack[topMap + 1])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA-1];
			lstackA--;
			lstackB++;
		}
		else if (topMap < STACK_SIZE-2 && stackA[lstackA-1] == sortedStack[topMap + 2] && stackB[lstackB-1] == sortedStack[topMap + 1])
		{
			moveA = "pb";
			stackB[lstackB] = stackA[lstackA-1];
			totalMoves++;
			lstackA--;
			lstackB++;
		}
		else if (stackA[lstackA-1] == sortedStack[bottomMap-1])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA-1];
			lstackA--;
			lstackB++;
			rotateRight(stackB, lstackB, 0,'b');
			moveB = "rb";
			totalMoves++;
		}
		else if(lstackA > 0)
		{
			//printArrays(sortedStack, stackA, stackB, topMap, lstackA, bottomMap, lstackB, bottomB, STACK_SIZE, lTrapB);
			if(!ft_strncmp(nextOp,"ra",2))
			{
				rotateLeft(stackA, lstackA, 0,'a');
				moveA = "ra";
			}
			else
			{
				rotateRight(stackA, lstackA, 0,'a');
				moveA = "rra";
			}
			totalMoves++;
		}

		// if (stackB[lstackB] == sortedStack[bottomB] && lTrapB[bottomB])
		// {
		// 	bottomB++;
		// }
		// else if (stackB[lstackB - 1] == sortedStack[lstackB - 1] && rTrapB)
		// {
		// 	lstackB--;
		// }
		// if (stackB[bottomB] < stackB[bottomB-1])
		// {
		// 	rotateLeft(stackB, lstackB, bottomB,'b');
		// 	moveB = "rb";
		// }
		/*else if (stackB[lstackB - 1] == sortedStack[bottomB] && lTrapB[bottomB])
		{
			rotateRight(stackB, lstackB, bottomB,'b');
			moveB = "rrb";
		}
		else if (stackB[bottomB] == sortedStack[lstackB - 1] && rTrapB)
		{
			rotateLeft(stackB, lstackB, bottomB,'b');
			moveB = "rb";
		}
		else if (stackB[bottomB + 1] == sortedStack[lstackB - 1] && rTrapB)
		{
			swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
			moveA = "sb";
		}
		else if(lTrapB[bottomB]){
			rotateLeft(stackB, lstackB, bottomB,'b');
			moveB = "rb";
		}*/
		// if(moveA "sa" && moveB=="sb"){
		// 	printf("ss ");
		// 	totalMoves++;
		// } else if(moveA == "ra" && moveB=="rb"){
		// 	printf("rr ");
		// 	totalMoves++;
		// } else {
			if(moveA != NULL){
				printf("%s ", moveA);
				totalMoves++;
			}
			if(moveB != NULL){
				printf("%s ", moveB);
				totalMoves++;
			}
		// }
		moveA = NULL;
		moveB=NULL;
		printf("total moves: %d\n", totalMoves);
		printArrays(sortedStack, stackA, stackB, topMap, lstackA, bottomMap, lstackB, bottomB, STACK_SIZE, lTrapB);
		printf("left B trap: %d right B trap: %d\n", lTrapB[bottomB], rTrapB);
		if (lstackB == STACK_SIZE)
			break;
	}
	// for (i =0; i<topMap; i++){
	// 	moveA = "pa";
	// 	stackA[topMap - i -1] = stackB[topMap - i -1];
	// 	totalMoves++;
	// }
	printf("total moves: %d\n", totalMoves);
	printArrays(sortedStack, stackA, stackB, topMap, STACK_SIZE, 0, STACK_SIZE, 0, STACK_SIZE, lTrapB);
	return (0);
}
		// if (isSorted(stackB, lstackB, bottomB, bigger) < lstackB - 1)
		// {
		// 	if (stackB[bottomB] == sortedStack[topMap - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		bottomB++;
		// 	}
		// 	else if (stackB[lstackB - 1] == sortedStack[topMap - lstackB] && rTrapB)
		// 	{
		// 		lstackB--;
		// 	}
		// 	if (stackB[bottomB+1] == sortedStack[topMap - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
		// 		moveA = "sb";
		// 	}
		// 	else if (stackB[lstackB - 1] == sortedStack[topMap - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		rotateRight(stackB, lstackB, bottomB,'b');
		// 		moveB = "rrb";
		// 	}
		// 	else if (stackB[bottomB] == sortedStack[lstackB - 1] && rTrapB)
		// 	{
		// 		rotateLeft(stackB, lstackB, bottomB,'b');
		// 		moveB = "rb";
		// 	}
		// 	else if (stackB[bottomB + 1] == sortedStack[lstackB - 1] && rTrapB)
		// 	{
		// 		swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
		// 		moveA = "sb";
		// 	}
		// 	else if(lTrapB[bottomB]){
		// 		rotateLeft(stackB, lstackB, bottomB,'b');
		// 		moveB = "rb";
		// 	}
		// }


