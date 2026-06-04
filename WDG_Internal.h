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

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef WDG_INTERNAL_H_
    #define WDG_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "WDG.h"
    #include "driver/STM32L496VGT6P/WDG_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef WDG_TIM
        #define WDG_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef WDG_LOG
        #define WDG_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define WDG_NAME       "WDG"
    #define WDG_LOG_PREFIX UTIL_StringConcatenateConstant( WDG_NAME, "> " )

    #ifdef DEBUG
        #define WDG_Raw( Level, Format, ... ) LOG_Raw( WDG_LOG, Level, Format, ##__VA_ARGS__ )
        #define WDG_Trace( Format, ... )      LOG_Trace( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define WDG_Debug( Format, ... )      LOG_Debug( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define WDG_Info( Format, ... )       LOG_Info( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define WDG_Warning( Format, ... )    LOG_Warning( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define WDG_Error( Format, ... )      LOG_Error( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define WDG_Fatal( Format, ... )      LOG_Fatal( WDG_LOG, UTIL_StringConcatenateConstant( WDG_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define WDG_Raw( Level, Format, ... )
        #define WDG_Trace( Format, ... )
        #define WDG_Debug( Format, ... )
        #define WDG_Info( Format, ... )
        #define WDG_Warning( Format, ... )
        #define WDG_Error( Format, ... )
        #define WDG_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum WDG_Type
    {
        WDG_Type_Unknown = 0,
        WDG_Type_Null,
        WDG_Type_STM32L496VGT6P,
    } WDG_Type_t;

    typedef struct WDG_Instance
    {
        WDG_Type_t Type;

        union
        {
            WDG_STM32L496VGT6P_t STM32L496VGT6Px;
        };
    } WDG_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    WDG_Status_t WDG_Port_Initialize( WDG_t WDGx );
    WDG_Status_t WDG_Port_Cycle( WDG_t WDGx );
    WDG_Status_t WDG_Port_DeInitialize( WDG_t WDGx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* WDG_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
