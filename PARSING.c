#include "inc/STD_TYPES.h"
#include "inc/GPS.h"
#include <stdlib.h>
#include <string.h>


float fGET_LATITUDE(volatile uint8* DATA){
    int d;
    float m;
    char firstPart[4]; // 0 d 1 d 2 m 3 m
    char lastPart[4]; // 0 m 1 m 2 m 3 m
    int n;
    char* intPart;
    char* fractionPart;
    int i;
	  char arr[82];
	  char* token;
  	int count = 0;
	for(i = 0; i < 82 ; i++){
		if(*(DATA+i) == '\0')
			break;
		arr[i] = *(DATA+i);
	}
    token = strtok (arr,",");
    while (token != NULL)
    {
        count++;
        token = strtok (NULL, ",");
        if(count == 1)
            break;
    }
    intPart = strtok (token,".");
    fractionPart = strtok (NULL, "\0");
    n = strlen(intPart);
    if(n == 1){
        for(i = 0; i < 4; i++){
            if(i == 0 || i == 1 || i == 2){
                firstPart[i] = '0';
            }
            else
                firstPart[i] = *(intPart+0);
        }
    }
    else if(n == 2){
        for(i = 0; i < 4; i++){
            if(i == 0 || i == 1){
                firstPart[i] = '0';
            }
            if(i == 2){
                firstPart[i] = *(intPart+(i-2));
            }
            if(i == 3){
                firstPart[i] = *(intPart+(i-2));
            }
        }
    }
    else if(n == 3){
            for(i = 0; i < 4; i++){
                if(i == 0){
                    firstPart[i] = '0';
                }
                else
                    firstPart[i] = *(intPart+(i-1));
            }

    }
    else if(n == 4){
        for(i = 0; i < 4; i++){
            firstPart[i] = *(intPart+i);
        }
    }
    for(i = 0; i < 4; i++){
        lastPart[i] = *(fractionPart+i);
    }
    d = (((firstPart[0] - '0') * 10) + (firstPart[1] - '0'));
    m = (((firstPart[2] - '0') * 10) + (firstPart[3] - '0') + ((float)(lastPart[0] - '0') / 10) + ((float)(lastPart[1] - '0') / 100) + ((float)(lastPart[2] - '0') / 1000) + ((float)(lastPart[3] - '0') / 10000));
    return (d + (m / 60.0));
}

float fGET_LONGITUDE(uint8* DATA){
    int d;
    float m;
    char firstPart[5]; // 0 d 1 d 2 m 3 m
    char lastPart[4]; // 0 m 1 m 2 m 3 m
    int n;
    char* intPart;
    char* fractionPart;
    int i;
	char arr[82];
	char* token;
	int count = 0;
	for(i = 0; i < 82 ; i++){
		if(*(DATA+i) == '\0')
			break;
		arr[i] = *(DATA+i);
	}
    token = strtok (arr,",");
    while (token != NULL)
    {
        count++;
        token = strtok (NULL, ",");
        if(count == 3)
            break;
    }
    intPart = strtok (token,".");
    fractionPart = strtok (NULL, "\0");
    n = strlen(intPart);
    if(n == 1){
        for(i = 0; i < 5; i++){
            if(i == 0 || i == 1 || i == 2 || i == 3){
                firstPart[i] = '0';
            }
            else
                firstPart[i] = *(intPart+0);
        }
    }
    else if(n == 2){
        for(i = 0; i < 5; i++){
            if(i == 0 || i == 1 || i == 2){
                firstPart[i] = '0';
            }
            if(i == 3){
                firstPart[i] = *(intPart+(i-2));
            }
            if(i == 4){
                firstPart[i] = *(intPart+(i-2));
            }
        }
    }
    else if(n == 3){
            for(i = 0; i < 5; i++){
                if(i == 0 || i == 1){
                    firstPart[i] = '0';
                }
                else
                    firstPart[i] = *(intPart+(i-2));
            }

    }
    else if(n == 4){
        for(i = 0; i < 5; i++){
            if(i == 0){
                firstPart[i] = '0';
            }
            else
                firstPart[i] = *(intPart+i);
        }
    }
    else if(n == 5){
        for(i = 0; i < 5; i++){
            firstPart[i] = *(intPart+i);
        }
    }
    for(i = 0; i < 4; i++){
        lastPart[i] = *(fractionPart+i);
    }
    d = ((((int)(firstPart[0] - '0')) * 100) + (firstPart[1] - '0') * 10) + (firstPart[2] - '0');
    m = (((firstPart[3] - '0') * 10) + (firstPart[4] - '0') + ((float)(lastPart[0] - '0') / 10) + ((float)(lastPart[1] - '0') / 100) + ((float)(lastPart[2] - '0') / 1000) + ((float)(lastPart[3] - '0') / 10000));
    return (d + (m / 60.0));
}
