#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int num)
{
    char strNum[100];
    sprintf(strNum, "%d", num);
  
    int length = 0;
    while(strNum[length]!='\0')
    {
        length++;        
    }

    for(int position = 0; position < length ; position++)
    {
        if(strNum[position] != strNum[length - position - 1])
        {
            return false;
        }
    }

    return true;
}

bool isPrime(long num)
{
    long maxDivisor = floor(sqrt(num));
    for(long divisor = 2; divisor <= maxDivisor; divisor++)
    {
        if(num % divisor == 0)
        {
            return false;
        }
    }

    return true;
}

void problem1()
{
    // Find the sum of all the multiples of 3 or 5 below 1000.
    int sum = 0;
    for(int i = 3; i<  1000; i++ )
    {
        if(i%3==0 || i%5==0)
        {
            sum += i;
        }
    }

   printf("Problem 1: %d \r\n", sum);
}

void problem2()
{
    // Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
    // 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
    // By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

    long fib1 = 1;
    long fib2 = 2;
    long fibNext = -1;
    long sum = 2;

    fibNext = fib1 + fib2;
    while(fibNext <= 4000000)
    {
        fib1 = fib2;
        fib2 = fibNext;

        if(fibNext%2==0)
        {
            sum+= fibNext;
        }

        fibNext = fib1 + fib2;
    }


    printf("Problem 2: %ld \r\n", sum);
}

void problem3()
{
    // What is the largest prime factor of the number 600851475143 ?

    long num = 600851475143L;

    long maxPrimeFactor = -1;

    for(long divisor = 2; divisor <= floor(sqrt(num)); divisor++)
    {
        if(num%divisor == 0)
        {
            long factor = divisor;
            if(isPrime(factor))
            {
                if(factor > maxPrimeFactor)
                {
                    maxPrimeFactor = factor;
                }
            }
        }
    } 

    printf("Problem 3: %ld \r\n", maxPrimeFactor);
}

void problem4()
{
    // A palindromic number reads the same both ways. 
    // The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
    // Find the largest palindrome made from the product of two 3-digit numbers.

    int largestPalindromeProduct = 0;
    int product = 0;
    int num1 = 0;
    int num2 = 0;

    for(num1 = 0; num1 < 1000; num1++)
    {
        for(num2 = 0; num2 < 1000; num2++)
        {
            product = num1 * num2; 
            if(isPalindrome(product))
            {
                if(product > largestPalindromeProduct)
                {
                    largestPalindromeProduct = product;
                }
            }
        }
    }

    printf("Problem 4: %d \r\n", largestPalindromeProduct);
}

void problem5()
{
    long ans = 1 * 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
    printf("Problem 5: %ld \r\n", ans);
}

void problem6()
{
    long sumOfSquares = 0;
    long squareOfSums = 0;

    for(int num = 1; num <=100 ; num++)
    {
        sumOfSquares += num * num;
        squareOfSums += num;
    }

    squareOfSums = squareOfSums * squareOfSums;

    printf("Problem 6: %ld \r\n", squareOfSums - sumOfSquares);
}

void problem7()
{
    int primeIndex = 1;
    long prime = 2;
    long nextPrime = -1;

    while(primeIndex < 10001)
    {
        nextPrime = prime+1;
        while(!isPrime(nextPrime))
        {
            nextPrime++;
        }

        prime = nextPrime;
        primeIndex++;
    }

    printf("Problem 7: %ld \r\n", prime);
}

void problem8()
{
    char strNum[1001];
    strcpy(strNum, "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
    

    long maxProduct = 0;
    long product = -1;

    for(int start = 0; start <= 988; start++)
    {
        product = 1;
        for(int length = 0; length < 13; length++)
        {
            int digit = strNum[start + length] - 48;
            product *= digit;
        }
        if(product > maxProduct)
        {
            maxProduct = product;
        }
    }

    printf("Problem 8: %ld \r\n", maxProduct);
}

void problem9()
{
    long result = 0;
    int a = -1;
    int b = -1;
    int c = -1;

    for(b = 2; b < 1000; b++) 
    {
        for(a = 1; a < b; a ++)
        {   
            c = 1000 - a - b;
            if(a*a+b*b == c*c)
            {
                result = a * b * c;
                break;
            }
        }
    }
    printf("Problem 9: %ld \r\n", result); 
}

void problem10()
{
    long prime = 2; //first prime
    long nextPrime = -1;
    long sumOfPrimes = 0;

    while(prime < 2000000)
    {
        sumOfPrimes += prime;
        nextPrime = prime+1;
        while(!isPrime(nextPrime))
        {
            nextPrime++;
        }

        prime = nextPrime;
    }

    printf("Problem 10: %ld \r\n", sumOfPrimes); 
}

void problem11() 
{
    int grid[20][20];

    grid[ 0][0] =  8; grid[ 0][1] =  2; grid[ 0][2] = 22; grid[ 0][3] = 97; grid[ 0][4] = 38; grid[ 0][5] = 15; grid[ 0][6] =  0; grid[ 0][7] = 40; grid[ 0][8] =  0; grid[ 0][9] = 75; grid[ 0][10] =  4; grid[ 0][11] =  5; grid[ 0][12] =  7; grid[ 0][13] = 78; grid[ 0][14] = 52; grid[ 0][15] = 12; grid[ 0][16] = 50; grid[ 0][17] = 77; grid[ 0][18] = 91; grid[ 0][19] =  8;
    grid[ 1][0] = 49; grid[ 1][1] = 49; grid[ 1][2] = 99; grid[ 1][3] = 40; grid[ 1][4] = 17; grid[ 1][5] = 81; grid[ 1][6] = 18; grid[ 1][7] = 57; grid[ 1][8] = 60; grid[ 1][9] = 87; grid[ 1][10] = 17; grid[ 1][11] = 40; grid[ 1][12] = 98; grid[ 1][13] = 43; grid[ 1][14] = 69; grid[ 1][15] = 48; grid[ 1][16] =  4; grid[ 1][17] = 56; grid[ 1][18] = 62; grid[ 1][19] =  0; 
    grid[ 2][0] = 81; grid[ 2][1] = 49; grid[ 2][2] = 31; grid[ 2][3] = 73; grid[ 2][4] = 55; grid[ 2][5] = 79; grid[ 2][6] = 14; grid[ 2][7] = 29; grid[ 2][8] = 93; grid[ 2][9] = 71; grid[ 2][10] = 40; grid[ 2][11] = 67; grid[ 2][12] = 53; grid[ 2][13] = 88; grid[ 2][14] = 30; grid[ 2][15] =  3; grid[ 2][16] = 49; grid[ 2][17] = 13; grid[ 2][18] = 36; grid[ 2][19] = 65;  
    grid[ 3][0] = 52; grid[ 3][1] = 70; grid[ 3][2] = 95; grid[ 3][3] = 23; grid[ 3][4] =  4; grid[ 3][5] = 60; grid[ 3][6] = 11; grid[ 3][7] = 42; grid[ 3][8] = 69; grid[ 3][9] = 24; grid[ 3][10] = 68; grid[ 3][11] = 56; grid[ 3][12] =  1; grid[ 3][13] = 32; grid[ 3][14] = 56; grid[ 3][15] = 71; grid[ 3][16] = 37; grid[ 3][17] =  2; grid[ 3][18] = 36; grid[ 3][19] = 91;  
    grid[ 4][0] = 22; grid[ 4][1] = 31; grid[ 4][2] = 16; grid[ 4][3] = 71; grid[ 4][4] = 51; grid[ 4][5] = 67; grid[ 4][6] = 63; grid[ 4][7] = 89; grid[ 4][8] = 41; grid[ 4][9] = 92; grid[ 4][10] = 36; grid[ 4][11] = 54; grid[ 4][12] = 22; grid[ 4][13] = 40; grid[ 4][14] = 40; grid[ 4][15] = 28; grid[ 4][16] = 66; grid[ 4][17] = 33; grid[ 4][18] = 13; grid[ 4][19] = 80;  
    grid[ 5][0] = 24; grid[ 5][1] = 47; grid[ 5][2] = 32; grid[ 5][3] = 60; grid[ 5][4] = 99; grid[ 5][5] =  3; grid[ 5][6] = 45; grid[ 5][7] =  2; grid[ 5][8] = 44; grid[ 5][9] = 75; grid[ 5][10] = 33; grid[ 5][11] = 53; grid[ 5][12] = 78; grid[ 5][13] = 36; grid[ 5][14] = 84; grid[ 5][15] = 20; grid[ 5][16] = 35; grid[ 5][17] = 17; grid[ 5][18] = 12; grid[ 5][19] = 50;  
    grid[ 6][0] = 32; grid[ 6][1] = 98; grid[ 6][2] = 81; grid[ 6][3] = 28; grid[ 6][4] = 64; grid[ 6][5] = 23; grid[ 6][6] = 67; grid[ 6][7] = 10; grid[ 6][8] = 26; grid[ 6][9] = 38; grid[ 6][10] = 40; grid[ 6][11] = 67; grid[ 6][12] = 59; grid[ 6][13] = 54; grid[ 6][14] = 70; grid[ 6][15] = 66; grid[ 6][16] = 18; grid[ 6][17] = 38; grid[ 6][18] = 64; grid[ 6][19] = 70;  
    grid[ 7][0] = 67; grid[ 7][1] = 26; grid[ 7][2] = 20; grid[ 7][3] = 68; grid[ 7][4] =  2; grid[ 7][5] = 62; grid[ 7][6] = 12; grid[ 7][7] = 20; grid[ 7][8] = 95; grid[ 7][9] = 63; grid[ 7][10] = 94; grid[ 7][11] = 39; grid[ 7][12] = 63; grid[ 7][13] =  8; grid[ 7][14] = 40; grid[ 7][15] = 91; grid[ 7][16] = 66; grid[ 7][17] = 49; grid[ 7][18] = 94; grid[ 7][19] = 21;  
    grid[ 8][0] = 24; grid[ 8][1] = 55; grid[ 8][2] = 58; grid[ 8][3] =  5; grid[ 8][4] = 66; grid[ 8][5] = 73; grid[ 8][6] = 99; grid[ 8][7] = 26; grid[ 8][8] = 97; grid[ 8][9] = 17; grid[ 8][10] = 78; grid[ 8][11] = 78; grid[ 8][12] = 96; grid[ 8][13] = 83; grid[ 8][14] = 14; grid[ 8][15] = 88; grid[ 8][16] = 34; grid[ 8][17] = 89; grid[ 8][18] = 63; grid[ 8][19] = 72;  
    grid[ 9][0] = 21; grid[ 9][1] = 36; grid[ 9][2] = 23; grid[ 9][3] =  9; grid[ 9][4] = 75; grid[ 9][5] =  0; grid[ 9][6] = 76; grid[ 9][7] = 44; grid[ 9][8] = 20; grid[ 9][9] = 45; grid[ 9][10] = 35; grid[ 9][11] = 14; grid[ 9][12] =  0; grid[ 9][13] = 61; grid[ 9][14] = 33; grid[ 9][15] = 97; grid[ 9][16] = 34; grid[ 9][17] = 31; grid[ 9][18] = 33; grid[ 9][19] = 95;  
    grid[10][0] = 78; grid[10][1] = 17; grid[10][2] = 53; grid[10][3] = 28; grid[10][4] = 22; grid[10][5] = 75; grid[10][6] = 31; grid[10][7] = 67; grid[10][8] = 15; grid[10][9] = 94; grid[10][10] =  3; grid[10][11] = 80; grid[10][12] =  4; grid[10][13] = 62; grid[10][14] = 16; grid[10][15] = 14; grid[10][16] =  9; grid[10][17] = 53; grid[10][18] = 56; grid[10][19] = 92;  
    grid[11][0] = 16; grid[11][1] = 39; grid[11][2] =  5; grid[11][3] = 42; grid[11][4] = 96; grid[11][5] = 35; grid[11][6] = 31; grid[11][7] = 47; grid[11][8] = 55; grid[11][9] = 58; grid[11][10] = 88; grid[11][11] = 24; grid[11][12] =  0; grid[11][13] = 17; grid[11][14] = 54; grid[11][15] = 24; grid[11][16] = 36; grid[11][17] = 29; grid[11][18] = 85; grid[11][19] = 57;  
    grid[12][0] = 86; grid[12][1] = 56; grid[12][2] =  0; grid[12][3] = 48; grid[12][4] = 35; grid[12][5] = 71; grid[12][6] = 89; grid[12][7] =  7; grid[12][8] =  5; grid[12][9] = 44; grid[12][10] = 44; grid[12][11] = 37; grid[12][12] = 44; grid[12][13] = 60; grid[12][14] = 21; grid[12][15] = 58; grid[12][16] = 51; grid[12][17] = 54; grid[12][18] = 17; grid[12][19] = 58;  
    grid[13][0] = 19; grid[13][1] = 80; grid[13][2] = 81; grid[13][3] = 68; grid[13][4] =  5; grid[13][5] = 94; grid[13][6] = 47; grid[13][7] = 69; grid[13][8] = 28; grid[13][9] = 73; grid[13][10] = 92; grid[13][11] = 13; grid[13][12] = 86; grid[13][13] = 52; grid[13][14] = 17; grid[13][15] = 77; grid[13][16] =  4; grid[13][17] = 89; grid[13][18] = 55; grid[13][19] = 40;  
    grid[14][0] =  4; grid[14][1] = 52; grid[14][2] =  8; grid[14][3] = 83; grid[14][4] = 97; grid[14][5] = 35; grid[14][6] = 99; grid[14][7] = 16; grid[14][8] =  7; grid[14][9] = 97; grid[14][10] = 57; grid[14][11] = 32; grid[14][12] = 16; grid[14][13] = 26; grid[14][14] = 26; grid[14][15] = 79; grid[14][16] = 33; grid[14][17] = 27; grid[14][18] = 98; grid[14][19] = 66;  
    grid[15][0] = 88; grid[15][1] = 36; grid[15][2] = 68; grid[15][3] = 87; grid[15][4] = 57; grid[15][5] = 62; grid[15][6] = 20; grid[15][7] = 72; grid[15][8] =  3; grid[15][9] = 46; grid[15][10] = 33; grid[15][11] = 67; grid[15][12] = 46; grid[15][13] = 55; grid[15][14] = 12; grid[15][15] = 32; grid[15][16] = 63; grid[15][17] = 93; grid[15][18] = 53; grid[15][19] = 69;  
    grid[16][0] =  4; grid[16][1] = 42; grid[16][2] = 16; grid[16][3] = 73; grid[16][4] = 38; grid[16][5] = 25; grid[16][6] = 39; grid[16][7] = 11; grid[16][8] = 24; grid[16][9] = 94; grid[16][10] = 72; grid[16][11] = 18; grid[16][12] =  8; grid[16][13] = 46; grid[16][14] = 29; grid[16][15] = 32; grid[16][16] = 40; grid[16][17] = 62; grid[16][18] = 76; grid[16][19] = 36;  
    grid[17][0] = 20; grid[17][1] = 69; grid[17][2] = 36; grid[17][3] = 41; grid[17][4] = 72; grid[17][5] = 30; grid[17][6] = 23; grid[17][7] = 88; grid[17][8] = 34; grid[17][9] = 62; grid[17][10] = 99; grid[17][11] = 69; grid[17][12] = 82; grid[17][13] = 67; grid[17][14] = 59; grid[17][15] = 85; grid[17][16] = 74; grid[17][17] =  4; grid[17][18] = 36; grid[17][19] = 16;  
    grid[18][0] = 20; grid[18][1] = 73; grid[18][2] = 35; grid[18][3] = 29; grid[18][4] = 78; grid[18][5] = 31; grid[18][6] = 90; grid[18][7] =  1; grid[18][8] = 74; grid[18][9] = 31; grid[18][10] = 49; grid[18][11] = 71; grid[18][12] = 48; grid[18][13] = 86; grid[18][14] = 81; grid[18][15] = 16; grid[18][16] = 23; grid[18][17] = 57; grid[18][18] =  5; grid[18][19] = 54;  
    grid[19][0] =  1; grid[19][1] = 70; grid[19][2] = 54; grid[19][3] = 71; grid[19][4] = 83; grid[19][5] = 51; grid[19][6] = 54; grid[19][7] = 69; grid[19][8] = 16; grid[19][9] = 92; grid[19][10] = 33; grid[19][11] = 48; grid[19][12] = 61; grid[19][13] = 43; grid[19][14] = 52; grid[19][15] =  1; grid[19][16] = 89; grid[19][17] = 19; grid[19][18] = 67; grid[19][19] = 48;
    
    //What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

    int maxProduct = -1;

    // Format is grid[y][x] !!!!!!!!!!!!!

    // Vertical
    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 17; y++)
        {
            int product = 
                  grid[y][x] 
                * grid[y+1][x]
                * grid[y+2][x]
                * grid[y+3][x];
            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }
    // Horizontal
    for(int x = 0; x < 17; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            int product = 
                  grid[y][x] 
                * grid[y][x+1]
                * grid[y][x+2]
                * grid[y][x+3];
            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }

    // Diagonal like "\"
    for(int x = 0; x < 17; x++)
    {
        for(int y = 0; y < 17; y++)
        {
            int product = 
                  grid[y][x] 
                * grid[y+1][x+1]
                * grid[y+2][x+2]
                * grid[y+3][x+3];
            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }

    // Diagonal like "/"
    for(int x = 3; x < 20; x++)
    {
        for(int y = 0; y < 17; y++)
        {
            int product = 
                  grid[y][x] 
                * grid[y+1][x-1]
                * grid[y+2][x-2]
                * grid[y+3][x-3];
            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }

    printf("Problem 11: %d \r\n", maxProduct); 
}

void problem12()
{

    printf("Problem 12: %ld \r\n", 0L); 
}

int main()
{
    problem1();
//    problem2();
//    problem3();
//    problem4();
//    problem5();
//    problem6();
//    problem7();
//    problem8();
//    problem9();
//    problem10(); 
//    problem11();
//    problem12();

    return 0;    //Exit gracefully
}