# Base_C

## Tools
- C
- Debian 10.2.1-6
- gcc 10.2.1
- GNU Make 4.3

## Description
*All programs are written by [ME](https://github.com/David2261 "Bulat Nasyrov") in C!
To compile the file more easily, I wrote a Makefile, with
which you can also run programs.
All binary files are stored in the build directory.*

## Project structure
- Functions
	-- Soft
- Lessons
- Math
- SMP

1. *In the **Functions** directory, simple programs are written thet perform operations such as:
bubble sort, character matching, palidrom, reverse, etc.*
2. *In the **Lessons** directory, written in inside this repository in a file [Readme](./Lessons/README.md)*
3. *In the **Math** directory, simple programs are written thet perform operations such as:
averange size, exponentiation, recursion, etc.*
4. *In the **SMP** directory, various functions from Kernighan Ritchie's book have been written.*


## Example

```c
int main() {
    int N = 0;
    if (scanf("%d", &N) != 1 || N < 1) {
        printf("n/a\n");
        return 1;
    }
    struct Human arr[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i].Name);
        scanf("%s", arr[i].Surname);
        if (scanf("%lf", &arr[i].size) != 1 || arr[i].size < 1) {
            printf("n/a\n");
            return 1;
        }
    }
    
    char name[100];
    scanf("%s", name);
    
    printf("str = %s\nname = %s\n", arr[0].Name, name);
    
    int count = 0;
    double sum = 0;
    
    for (int i = 0; i < N; i++) {
        if (strcmp21(name, arr[i].Name) == 0) {
            count++;
            sum += arr[i].size * 1.0;
            printf("%s, ", arr[i].Surname);
        }
    }
    printf("\b\b");
    printf(" : %0.lf\n", (sum / count));
    
    return 0;
}
```
