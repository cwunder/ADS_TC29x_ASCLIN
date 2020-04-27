/**********************************************************************************************************************
 * \file Ifx_Cfg.h
 * \brief Project configuration file.
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef IFX_CFG_H
#define IFX_CFG_H 1

/*********************************************************************************************************************/
/*------------------------------------------Configuration for IfxScu_cfg.h-------------------------------------------*/
/*********************************************************************************************************************/
/* External oscillator frequency in Hz */
#define IFX_CFG_SCU_XTAL_FREQUENCY      (20000000)  /* Allowed values are: 16000000, 20000000 or 40000000 */
/* PLL frequency in Hz */
#define IFX_CFG_SCU_PLL_FREQUENCY       (200000000) /* Allowed values are: 80000000, 133000000, 160000000, 200000000,
                                                     * 240000000 or 300000000 */

/*********************************************************************************************************************/
/*-----------------------------------Configuration for Software managed interrupt------------------------------------*/
/*********************************************************************************************************************/
/* #define IFX_USE_SW_MANAGED_INT */ /* Decomment this line if the project needs to use Software managed interrupts */

/*********************************************************************************************************************/
/*---------------------------------Configuration for Trap Hook Functions' Extensions---------------------------------*/
/*********************************************************************************************************************/
/* #define IFX_CFG_EXTEND_TRAP_HOOKS */ /* Decomment this line if the project needs to extend trap hook functions */

#endif /* IFX_CFG_H */
