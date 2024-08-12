/*
 * MIT License
 *
 * Copyright (c) [2024] By_Co
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to the following 
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT 
 * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR 
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * Granted by By_Co.
 */

#ifndef DATABASE_H
#define DATABASE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ---------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
/* End Includes -----------------------------------------------------------------------*/

/* Macros -----------------------------------------------------------------------------*/
#define LENGTH_DATABASE                 250
#define LENGHT_MAX_NAME_TEST            20
#define LENGTH_MAX_NAME_GLOBAL_TEST     20       
#define LENGTH_NAME_STRIP_SUPPLIER      20
#define LENGTH_NAME_TEST_PAD            20
#define QUANTITY_MAX_TEST_PADS          10
#define QUANTITY_MAX_REACTIVE_ELEMENTS  15
#define QUANTITY_MIN_PADS               1
/* End Macros -------------------------------------------------------------------------*/
/* Typedefs ---------------------------------------------------------------------------*/
typedef struct rgb{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
}rgb_t;

typedef struct pads{
    rgb_t rgb;
    char reaction_pad[LENGTH_NAME_TEST_PAD];
}pads_t;


typedef struct reactive_elements{   
    char name_test[LENGHT_MAX_NAME_TEST];
    uint8_t quantity_reaction_zones;
    pads_t pads_array[QUANTITY_MAX_TEST_PADS];
}reactive_elements_t;

typedef struct comparative_table_record{
    char name_global_test[LENGTH_MAX_NAME_GLOBAL_TEST];
    char name_reagent_strip_supplier[LENGTH_NAME_STRIP_SUPPLIER];
    uint8_t quantity_reactive_elements;
    reactive_elements_t reactive_elements_array[QUANTITY_MAX_REACTIVE_ELEMENTS]; 
}comparative_table_record_t;


/* End Typedefs -----------------------------------------------------------------------*/

/* Constants --------------------------------------------------------------------------*/
/* End Constants ----------------------------------------------------------------------*/

/* Global Variables -------------------------------------------------------------------*/
/* End Global Variables ---------------------------------------------------------------*/

/* Function Prototypes ----------------------------------------------------------------*/
bool init_database();
int create_record_db_ctr(comparative_table_record_t * record);
/* End Function Prototypes ------------------------------------------------------------*/

/* Preprocessor directives ------------------------------------------------------------*/
#if  QUANTITY_MAX_TEST_PADS < 1 
#error "QUANTITY_MIN_TEST_PADS MUST BE LESS OR EQUAL THAT 1"
#endif

/* End preprocessor directives --------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif/* DATABASE_h */
