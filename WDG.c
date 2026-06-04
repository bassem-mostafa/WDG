// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "WDG.h"
#include "WDG_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct WDG_Context
{
} WDG_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static WDG_Status_t WDG_Context_Initialize( void );
static WDG_Status_t WDG_Context_Cycle( void );
static WDG_Status_t WDG_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static WDG_Context_t WDG_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static WDG_Status_t WDG_Context_Initialize( void )
{
    WDG_Status_t Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( WDG_Context );
    }
    while ( 0 );

    return Status;
}

static WDG_Status_t WDG_Context_Cycle( void )
{
    WDG_Status_t Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( WDG_Context );
    }
    while ( 0 );

    return Status;
}

static WDG_Status_t WDG_Context_DeInitialize( void )
{
    WDG_Status_t Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( WDG_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

WDG_Status_t WDG_Initialize( WDG_t WDGx )
{
    WDG_Status_t Status = WDG_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( WDGx=%d )", __FUNCTION__, WDGx );

        if ( ( Status = WDG_Context_Initialize( ) ) != WDG_Status_Success )
        {
            break;
        }

        WDG_t WDG_start = ( WDGx == WDG_All ? WDG_Null : WDGx );
        WDG_t WDG_end = ( WDGx == WDG_All ? WDG_Count : WDGx + 1 );
        for ( WDG_t WDG_x = WDG_start; WDG_x < WDG_end; ++WDG_x )
        {
            if ( ( WDG_Status = WDG_Port_Initialize( WDG_x ) ) != WDG_Status_Success )
            {
                Status = WDG_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

WDG_Status_t WDG_Cycle( WDG_t WDGx )
{
    WDG_Status_t Status = WDG_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( WDGx=%d )", __FUNCTION__, WDGx );

        if ( ( Status = WDG_Context_Cycle( ) ) != WDG_Status_Success )
        {
            break;
        }

        WDG_t WDG_start = ( WDGx == WDG_All ? WDG_Null : WDGx );
        WDG_t WDG_end = ( WDGx == WDG_All ? WDG_Count : WDGx + 1 );
        for ( WDG_t WDG_x = WDG_start; WDG_x < WDG_end; ++WDG_x )
        {
            if ( ( WDG_Status = WDG_Port_Cycle( WDG_x ) ) != WDG_Status_Success )
            {
                Status = WDG_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

WDG_Status_t WDG_DeInitialize( WDG_t WDGx )
{
    WDG_Status_t Status = WDG_Status_Success;
    WDG_Status_t WDG_Status = WDG_Status_Success;

    do
    {
        WDG_Trace( "%s( WDGx=%d )", __FUNCTION__, WDGx );

        WDG_t WDG_start = ( WDGx == WDG_All ? WDG_Null : WDGx );
        WDG_t WDG_end = ( WDGx == WDG_All ? WDG_Count : WDGx + 1 );
        for ( WDG_t WDG_x = WDG_start; WDG_x < WDG_end; ++WDG_x )
        {
            if ( ( WDG_Status = WDG_Port_DeInitialize( WDG_x ) ) != WDG_Status_Success )
            {
                Status = WDG_Status;
            }
        }

        if ( ( WDG_Status = WDG_Context_DeInitialize( ) ) != WDG_Status_Success )
        {
            Status = WDG_Status;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char WDG_VERSION[] = "0.0.0.v20260604-0241";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
