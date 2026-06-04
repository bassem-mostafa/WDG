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

/**
 *  @file
 *
 *  @brief Platform WDG Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_WDG WDG
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_WDG_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef WDG_H_
    #define WDG_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "WDG_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief WDG Operation Status
     *
     *  @enum WDG_Status_t
     */
    typedef enum WDG_Status
    {
        WDG_Status_Success = 0,     ///< Success
        WDG_Status_ArgumentInvalid, ///< Argument Invalid
        WDG_Status_NotSupported,    ///< Not Supported
        WDG_Status_Error,           ///< General Error
        WDG_Status_Busy,            ///< Busy
        WDG_Status_Timeout,         ///< Timeout
    } WDG_Status_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize WDG peripheral
     *
     *  @note MUST BE called before using any WDG API
     *
     *  @param[in] WDGx Peripheral
     *
     *  @return WDG_Status_t
     */
    WDG_Status_t WDG_Initialize( WDG_t WDGx );

    /**
     *  @brief Cycle WDG peripheral
     *
     *  @param[in] WDGx Peripheral
     *
     *  @return WDG_Status_t
     */
    WDG_Status_t WDG_Cycle( WDG_t WDGx );

    /**
     *  @brief De-Initialize WDG peripheral
     *
     *  @param[in] WDGx Peripheral
     *
     *  @return WDG_Status_t
     */
    WDG_Status_t WDG_DeInitialize( WDG_t WDGx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char WDG_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* WDG_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
