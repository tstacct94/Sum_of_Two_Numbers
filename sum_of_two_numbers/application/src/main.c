/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name    : helloworld.c
 * Version      : 0.7.0
 * Product Name : Hello application
 * Device(s)    : V3H1, V3H2, V3M2, V3U, V4H
 * Description  : -
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * History   Version   DD.MM.YYYY    Description
 *           0.4.0     02.07.2021    Add doxygen comment
 *           0.5.0     15.07.2021    Add eMCOS support
 *           0.6.0     14.10.2021    Fix cast issue
 *           0.7.0     08.11.2021    Update helloworld thread_id, remove eMCOS specific code
***********************************************************************************************************************/

/* Includes */
#include "rcar-xos/rcar_xos_config.h"
#include "stdio.h"
#include "rcar-xos/osal/r_osal.h"
#include "stdlib.h"
/*******************************************************************************************************************//**
 * @defgroup Helloworld_Private_Defines Private macro definitions
 *
 * @{
 **********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @def PRINT_ERROR
 * Print error macro follow template ERROR: <function_name> (<line>) : <message>
***********************************************************************************************************************/

#define PRINT_ERROR(...) { printf("ERROR: %s (%d): ", __func__, __LINE__); printf(__VA_ARGS__);}
/** @} */

/******************************************************************************************************************//**
 * @defgroup Helloworld_Private_Functions Private function definitions
 *
 * @{
*********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief     Print build information which makes use of definition from rcar_xos_config.h
 *  - Compile date, time
 *  - RCar xOS information: OS, SoC, Git information (origin, tag, branch, hash)
 * @param[in] app_name Application name.
***********************************************************************************************************************/
/* Get rcar xos information */
void print_build_info(char *app_name)
{
    printf("/******************************************************************/\n");
    printf(" * Application information: %s\n", app_name);
    printf(" *   Build Date:    " __DATE__ " at " __TIME__ "\n");
    printf(" *\n");
    printf(" * R-Car xOS information:\n");
    printf(" *   OS:            " RCAR_XOS_OS "\n");
    printf(" *   Target:        " RCAR_XOS_TARGET "\n");
    printf(" *   Git Origin:    " RCAR_XOS_GIT_ORIGIN_URL "\n");
#ifdef RCAR_XOS_GIT_TAG_NAME
#ifndef RCAR_XOS_GIT_TAG_IS_AHEAD
    printf(" *   Git Tag:       " RCAR_XOS_GIT_TAG_NAME "\n");
#else
    printf(" *   Git Tag:       " RCAR_XOS_GIT_TAG_NAME
           " (" RCAR_XOS_GIT_NO_COMMITS_HEAD_OF_TAG " commits ahead)" "\n");
#endif
#endif
    printf(" *   Git Branch:    "  RCAR_XOS_GIT_BRANCH "\n");
    printf(" *   Git Hash:      "  RCAR_XOS_GIT_COMMIT_HASH "\n");
    printf(" *\n");
    printf("/******************************************************************/\n");
}


/******************************************************************************************************************//**
 * @brief    sum of two numbers main function.
 		inputs: number1, number2 and sum; 
 		If the entered sum is actual sum of entered numbers you will get congratulation message otherwise you will get sorry message along with actual sum
 * @return   0 on success
 * 
***********************************************************************************************************************/
int main(int argc, char * argv[])
{
    (void)argc;  /* unused */
    /* (void)argv;  unused */
    
   int a;
   int b;
   int c;
  
    
   if ((argc != 0) && (argc == 4))
   {
    

    print_build_info("sum_of_two_numbers");
    
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
      
    if ((a+b) == c)
    {
    
     printf("Congratulations! You Are Correct\n");
    
    }
    else
    {
     printf("Sorry! You Are Wrong\n");
     printf("sum = %d\n", a+b);
    }
    
    
    return 0;
    }
    else
    {
    printf("Please enter three numbers\n");
    return 0;
    }
}
/** @} */
