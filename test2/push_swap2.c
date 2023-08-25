#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
char *rotateUp(int *stack, int length, int bottom, char id)
{
	int	temp;
	char *ret;

	ret = ft_strnew(2);
	temp = stack[bottom];
	for (int i = bottom; i < length ; i++)
	{
		stack[i] = stack[i + 1];
	}
	stack[length] = temp;
	ret[0] = 'r';
	ret[1] = id;
	return ret;
}

char *rotateDown(int *stack, int length, int bottom, char id)
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
void printArrays(int sortedStack[], int stackA[], int stackB[], int targetIndex, int lstackA, int bottomA, int lstackB, int bottomB, int length, int lTrapB[]) {
	printf("%*s|%*s\n", (bottomA +1) * 3 + 11, "bottomA", (targetIndex - bottomA + 1) * 3 + 8, "|targetIndex");
    printf("sortedStack: ");
    for (int i = 0; i < length; i++) {
        printf("%2d ", sortedStack[i]);
    }
    printf("\n");


	printf("%*s|\n", (lstackA + 1)  * 3 + 11, "lstackA");
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
    printf("%*s|\n", (lstackB + 1)  * 3 + 11, "lstackB");
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
	int	lstackA;
	int	lstackB;
	int	targetIndex;
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
	lstackA = STACK_SIZE-1;
	lstackB = 0;
	int bottomA = 0;
	int bottomB = 0;
	targetIndex = STACK_SIZE-1;
	currentIndex = 0;
	int totalMoves = 0;
	char *moveA = NULL;
	char *moveB = NULL;
	int rTrapB = 0;
	int nextMove =0;

	while (1)
	{
		int nPosBottom = findElement(stackA, sortedStack[bottomA], lstackA + 1);
		int nPosUpper = findElement(stackA, sortedStack[targetIndex], lstackA + 1);
		int nMinMovesBottom;
		int nMinMovesUpper;
		char *nextOp;
		char *nextOpBottom;
		char *nextOpUpper;
		if(nPosBottom <lstackA - nPosBottom)
		{
			nMinMovesBottom = nPosBottom;
			nextOpBottom = "ra";
		}
		else
		{
			nMinMovesBottom = lstackA - nPosBottom;
			nextOpBottom = "rra";
		}
		if(nPosUpper <lstackA - nPosUpper)
		{
			nMinMovesUpper = nPosUpper;
			nextOpUpper = "ra";
		}
		else
		{
			nMinMovesUpper = lstackA - nPosUpper;
			nextOpUpper = "rra";
		}
		if(nMinMovesBottom < nMinMovesUpper)
		{
			nextOp = nextOpBottom;
		}
		else
		{
			nextOp = nextOpUpper;
		}
		if (stackA[lstackA] == sortedStack[targetIndex])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA];
			targetIndex--;
			lstackA--;
			lstackB++;
			rotateDown(stackB, lstackB, 0,'b');
			moveB = "rb";
			totalMoves++;
		}
		//Lock the smallest in the second half
		else if (stackA[lstackA] == sortedStack[bottomA])
		{
			moveA = "pb";
			totalMoves++;
			stackB[lstackB] = stackA[lstackA];
			lstackA--;
			lstackB++;
			bottomA++;
		}
		// else if (stackA[lstackA] > stackA[lstackA - 1] && stackA[lstackA]!=sortedStack[targetIndex])
		// {
		// 	swap(&stackA[lstackA], &stackA[lstackA - 1],'a');
		// 	moveA = "sa";
		// }
		else //if (stackA[lstackA] < sortedStack[targetIndex])
		{
			if(nextOp == "ra")
			{
				rotateUp(stackA, lstackA, 0,'a');
				moveA = "ra";
			}
			else
			{
				rotateDown(stackA, lstackA, 0,'a');
				moveA = "rra";
			}
		}
		/*if (isSorted(stackB, lstackB, bottomB, smaller) < lstackB - 1)
		{
			if (stackB[bottomB] == sortedStack[bottomB] && lTrapB[bottomB])
			{
				bottomB++;
			}
			else if (stackB[lstackB - 1] == sortedStack[lstackB - 1] && rTrapB)
			{
				lstackB--;
			}
			else if (stackB[bottomB+1] == sortedStack[bottomB] && lTrapB[bottomB])
			{
				swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
				moveA = "sb";
			}
			else if (stackB[lstackB - 1] == sortedStack[bottomB] && lTrapB[bottomB])
			{
				rotateDown(stackB, lstackB, bottomB,'b');
				moveB = "rrb";
			}
			else if (stackB[bottomB] == sortedStack[lstackB - 1] && rTrapB)
			{
				rotateUp(stackB, lstackB, bottomB,'b');
				moveB = "rb";
			}
			else if (stackB[bottomB + 1] == sortedStack[lstackB - 1] && rTrapB)
			{
				swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
				moveA = "sb";
			}
			else if(lTrapB[bottomB]){
				rotateUp(stackB, lstackB, bottomB,'b');
				moveB = "rb";
			}
		}*/
		if(moveA == "sa" && moveB=="sb"){
			printf("ss ");
			totalMoves++;
		} else if(moveA == "ra" && moveB=="rb"){
			printf("rr ");
			totalMoves++;
		} else {
			if(moveA != NULL){
				printf("%s ", moveA);
				totalMoves++;
			}
			if(moveB != NULL){
				printf("%s ", moveB);
				totalMoves++;
			}
		}
		moveA = NULL;
		moveB=NULL;
		printf("total moves: %d\n", totalMoves);
		printArrays(sortedStack, stackA, stackB, targetIndex, lstackA, bottomA, lstackB, bottomB, STACK_SIZE, lTrapB);
		printf("left B trap: %d right B trap: %d\n", lTrapB[bottomB], rTrapB);
		if (lstackB == STACK_SIZE)
			break;
	}
	// for (i =0; i<targetIndex; i++){
	// 	moveA = "pa";
	// 	stackA[targetIndex - i -1] = stackB[targetIndex - i -1];
	// 	totalMoves++;
	// }
	printf("total moves: %d\n", totalMoves);
	printArrays(sortedStack, stackA, stackB, targetIndex, STACK_SIZE, 0, STACK_SIZE, 0, STACK_SIZE, lTrapB);
	return (0);
}
		// if (isSorted(stackB, lstackB, bottomB, bigger) < lstackB - 1)
		// {
		// 	if (stackB[bottomB] == sortedStack[targetIndex - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		bottomB++;
		// 	}
		// 	else if (stackB[lstackB - 1] == sortedStack[targetIndex - lstackB] && rTrapB)
		// 	{
		// 		lstackB--;
		// 	}
		// 	if (stackB[bottomB+1] == sortedStack[targetIndex - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
		// 		moveA = "sb";
		// 	}
		// 	else if (stackB[lstackB - 1] == sortedStack[targetIndex - bottomB - 1] && lTrapB[bottomB])
		// 	{
		// 		rotateDown(stackB, lstackB, bottomB,'b');
		// 		moveB = "rrb";
		// 	}
		// 	else if (stackB[bottomB] == sortedStack[lstackB - 1] && rTrapB)
		// 	{
		// 		rotateUp(stackB, lstackB, bottomB,'b');
		// 		moveB = "rb";
		// 	}
		// 	else if (stackB[bottomB + 1] == sortedStack[lstackB - 1] && rTrapB)
		// 	{
		// 		swap(&stackB[bottomB], &stackB[bottomB + 1],'b');
		// 		moveA = "sb";
		// 	}
		// 	else if(lTrapB[bottomB]){
		// 		rotateUp(stackB, lstackB, bottomB,'b');
		// 		moveB = "rb";
		// 	}
		// }


