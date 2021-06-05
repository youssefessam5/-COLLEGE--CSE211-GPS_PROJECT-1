#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#ifndef CHECK_BIT
#define CHECK_BIT(R, B) (R) &= (1U<<B) //CHECKS THE BIT IF IT IS 1
#endif

#ifndef SET_BITS
#define SET_BITS(R, V, B) (R) |=(V<<B) // SETS BITS TO A SPECIFIC VALUE EX: R |= (0x3<<2) // sets bits 2, 3
#endif

#ifndef CLEAR_BITS
#define CLEAR_BITS(R, V, B) (R) &=~(V<<B)
#endif

#ifndef SET_BIT
#define SET_BIT(R, B) (R)|=(1U<<(B)) //r for Register, x for bit index
#endif

#ifndef TOGGLE_BIT
#define TOGGLE_BIT(R, B) (R)^=(1U<<(B)) //r for Register, x for bit index
#endif                              
																		
#ifndef CLEAR_BIT                   
#define CLEAR_BIT(R, B) (R)&=~(1U<<(B)) //r for Register, x for bit index
#endif                              

#ifndef TRUE
#define TRUE (1u)
#endif

#ifndef FALSE
#define FALSE (0u)
#endif

typedef unsigned char uint8; // 0 - 255
typedef signed char sint8; // -128 - 127
typedef unsigned short uint16; // 0 - 65536
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#endif
