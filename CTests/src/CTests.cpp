#include <stdio.h>
#include <stdint.h>


//------------------------------------------------------
// START
// Q: What will be printed by the following code?
//
// Result:
//      m = 0
//      x = -2
// Explanation: in the ABS macros substitution, ++n is executed twice: (((++ -2) ? (++ -2) : (++ -2)

#define MAX(a,b) a*b
#define ABS(x) (((x) < 0) ? -(x) : (x))

int ff1(int n)
{
    int m = ABS(++n);
    printf("m = %d\n", m);

    return n;
}

int f1()
{
    printf("f1: ABS(x)\n");

    int x = -2;

    ff1(x);
        
    printf("x = %d", x);

    return 0;
}

// END
//------------------------------------------------------


//------------------------------------------------------
// START
// Q: What will be printed by the following code?
//
// Result: This is 12 years old.

#define YEARS_OLD 12
#ifndef YEARS_OLD
#define YEARS_OLD 10
#endif

int f2()
{
    printf("f2: #define YEARS_OLD\n");
    printf("This is %d years old.\n", YEARS_OLD);

    return 0;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What is the output of following code?
//
// Result: 0 1 2 3 4 5 6 7 8 9

int f3()
{
    printf("f3: static var\n");

    static int i;

    do
    {
        printf("%d ", i++);

    } while (i < 10);

    return 0;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code output and why?
//
// Result: > 6
// Explanation: according to the integer promotion rules in C, signed integers get promoted to unsigned integers!
// Expressions involving signed and unsigned types have all operands promoted to unsigned types.
// Thus, -20 becomes a very large positive integer and the expression evaluates to greater than 6.

void f4(void)
{
    printf("f4: integer promotion\n");

    unsigned int a = 6;
    int b = -20;

    (a + b > 6) ? puts("> 6") : puts("<= 6");
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What will be printed by the following code?
//
// Result: 
//         x = 1
//         y = 1

int f5()
{
    printf("f5: '=' instead of '==' \n");

    int x = 10;
    char y = 0;

    for (;;)
    {
        if (x = y)
            break;

        x--;
        y++;
    }

    printf("x = %d\n", x);
    printf("y = %d", y);

    return 0;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What is the return of the function compute(20, 30)?
//
// Result: x = 590

#define SUM(A,B) A+B
#define DIF(A,B) A-B

int compute(int i, int j)
{
    return SUM(i, j) * DIF(i, j);
}

int f6()
{
    printf("f6: wrong writen macro (no parantheses)\n");

    int x = compute(20, 30);

    printf("x = %d\n", x);

    return 0;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What is the output of the function?
//
// Result: x = 0

int f7()
{
    printf("f7: Bitwise operations XOR and AND\n");

    int x;
    int a, b, c;

    a = 0x1F;
    b = 0xF1;
    c = 0x11;

    x = (a ^ b) & c;

    printf("x = %d\n", x);

    return 0;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: Length of s

int f8(const char* s)
{
    printf("f8: Lenght of a char\n");

    const char* t = s;

    while (*s) s++;

    return s - t;
}
 
// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: transforms 'char' parameter to its decimal equivalent (base 10)

int f9(const char* p)
{
    printf("f9: transforms 'char' parameter to its decimal equivalent (base 10)\n");

    int k = 0;

    while (*p)
    {
        k = 10 * k + (*p) - '0';
        p++;
    }

    return k;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: Returns the number of leading 0 bits in the reprezentation of p
// Better name: 'NumberOfLeadingZeros'

uint32_t f10(uint32_t p)
{
    printf("f10: Returns the number of leading 0 bits in the reprezentation of the parameter\n");

    uint32_t mask = 0x80000000u;
    uint32_t retval = 0u;

    while (((p & mask) == 0u) && (mask != 0u))
    {
        retval++;
        mask >>= 1u;
    }

    return retval;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: Returns the number of 0 bits in the reprezentation of p
// Better name: 'NumberOfZeros'

uint32_t f11(uint32_t p)
{
    printf("f11: Returns the number of 0 bits in the reprezentation of the parameter\n");

    uint32_t mask = 0x80000000u;
    uint32_t retval = 0u;
        
    while(mask != 0u)
    {
        if((p & mask) == 0u)
             retval++;
       
        mask >>= 1u;
    }

    return retval;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Below code contains some bugs and other problems.
// Please do a review and point out your findings.
//
// Result: explain
/*
#define htons(s) ((s<<8u)|(s>>8u))
#define TOP 15u
#define BOTTOM 0u

extern unsigned a[15];
extern void debug_log(short n);

unsigned f12(void)
{
    printf("f12: Find the bug\n");

    unsigned sum;
    short i = TOP;

    while (i >= BOTTOM)
    {
        sum += a[i];
        debug_log(htons(i--));
    }

    return sum;
}
*/
// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Implement a swap function in C which can be used to interchange two integer values.
// Variables aand b should have changed values in main().
//
// Note: Do not use any library calls, but implement your solution in plain C.
//
// Result: implement the Swap function

void swap(int* a, int* b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

int f13()
{
    printf("f13: Write and test the swap fuction\n");

    int a, b;

    a = 5;
    b = 10;

    printf("a: %d\t b: %d\n", a, b);

    swap(&a, &b);

    printf("a: %d\t b: %d\n", a, b);

    return 0;
}

// END
//------------------------------------------------------

// ------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: b1 = 1 (if a == b) or b1 = 0 (if a != b)

int f14(int a, int b)
{
    printf("f14: '=' and '=='\n");

    int b1 = a == b;

    return b1;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do?
//
// Result: reverse / mirror of an int
// ex: x = 2468 --> r = 8642

int f15(int x)
{
    printf("f15: reverse / mirror of an int\n");

    int r = 0;

    do
    {
        r = 10 * r + x % 10;

        x /= 10;
    } while (x != 0);

    return r;
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What will be printed?
//
// Result: 0

void f16()
{
    printf("f16: compares unsigned int 1 with int -1\n");

    int si = -1;
    unsigned int ui = 1;
    printf("%d\n", si < ui);
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do ? Why would anyone write something like that ?
//
// Result: Duff's Device is a way of manually implementing loop unrolling by interleaving two syntactic constructs of C: the do-while loop
// and a switch statement.
// Link: https://www.drdobbs.com/a-reusable-duff-device/184406208?queryText=%2Bduff%2527s%2Bdevice

#include<string.h>
#include <stdlib.h>

void copyBoolArray(bool* pSource, bool* pDest, int len)
{
    printf("f17: Duff's Device\n");

    int n = len / 8;
//    int n = (len + 8 - 1) / 8;

    switch (len % 8)
    {
    case 0:
        do {
            *pDest++ = *pSource++;
    case 7: *pDest++ = *pSource++;
    case 6: *pDest++ = *pSource++;
    case 5: *pDest++ = *pSource++;
    case 4: *pDest++ = *pSource++;
    case 3: *pDest++ = *pSource++;
    case 2: *pDest++ = *pSource++;
    case 1: *pDest++ = *pSource++;
        } while (--n >= 0);
    }
}

// Driver code
void f17()
{
    int size = 20;
    bool dest[20], src[20];

    // Assign some random values to src[]
    int i;
    for (i = 0; i < size; i++)
        src[i] = rand() % 2;

    for (i = 0; i < size; i++)
        printf("src: %d\t dest: %d\n", src[i], dest[i]);

    copyBoolArray(src, dest, size);

    for (i = 0; i < size; i++)
        printf("src: %d\t dest: %d\n", src[i], dest[i]);
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: What does the following code do ? Why would anyone write something like that ?
//
// Result:  square(x) - Unintended result - lack of paranthesis in the macro will result in (64/4) * 4
//          CUBE(x): ++ operator is executed 3 times before the actual multiplication

#define square(x) x*x
#define CUBE(x) (x*x*x)

void f18()
{
    int i;
    int p = 4;
    i = 64 / square(p);
    printf("square(x) x*x - Unintended result\n");
    printf("64 / square(%d) is %d\n",p, i);
    printf("\n");

    int x, y;
    x = 5;

    y = CUBE(++x);
   
    printf("CUBE(x) (x*x*x) - ++ operator is executed 3 times before the actual multiplication \n");
    
    printf("CUBE(%d) is % d\n", x, y );
}

// END
//------------------------------------------------------

//------------------------------------------------------
// START
// Q: 
//
// Result:  
/*
#pragma pack(2)

#define MAX-NUM-OF_CURVES   512

typedef enum
{
    ECC_CURVE_TYPE_A = 0x2B93U,
    ECC_CURVE_TYPE_B,
    ECC_CURVE_TYPE_C
} eccCurveType_t;

typedef struct
{
    eccCurveType_t curveType;
    eccCurveId_t curveId;       // uint8_t
    keyBits_t curveBitsLen;     // uint16_t
};

extern eccCurve_t gEccCurves;

volatile uint32_t gKeyCounter;

static uint8_t romKey[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF  };

const eccCurve_t* getEccCurve(eccCurveId_t eccCurveId)
{
    uint8_t i = 0;
    const eccCurve_t* pEccCurve = NULL;

    if(eccCurveIs < 0xAU)
    {
        for (i = 0; i < MAX_NUM_OF_CURVES; i++)
        {
            if (gEccCurves[i]eccCurveId == eccCurveId)
            {
                pEccCurve = &gEccCurve[i];
                pEccCurve->eccCurveId = i;
                break;
            }
        }
    }
    else
    {
        pEccCurve = NULL;
    }

    return pEccCurve;
}
*/
void f19()
{
    printf("f19\n");
}

// END
//------------------------------------------------------

//#include "\xM\DEV\CProjects\InterviuTests\include\Def.h"
int Global = 10;

int main()
{
    int x;

    f1();
    printf("\n");

    printf("\n");
    f2();
    printf("\n");

    f3();
    printf("\n");

    printf("\n");
    f4();
    printf("\n");

    f5();
    printf("\n");

    printf("\n");
    f6();

    printf("\n");
    f7();

    printf("\n");
    x = f8("123456");
    printf("x = %d\n", x);

    printf("\n");
    x = f9("1234567");
    printf("x = %d\n", x);
 
    printf("\n");
    x = f10(8);
    printf("x = %d\n", x);

    printf("\n");
    x = f11(8);
    printf("x = %d\n", x);

    // Not tested
    // f12();

    // swap function
    printf("\n");
    f13();

    printf("\n");
    x = f14(12, 12);
    printf("x = %d\n", x);

    printf("\n");
    x = f15(123456789);
    printf("x = %d\n", x);

    printf("\n");
    f16();

    printf("\n");
    f17();

    printf("\n");
    f18();
   
    printf("\n");
    f19();

    printf("\n");
    printf("Global variable = %d", Global);

    return 0;
}
