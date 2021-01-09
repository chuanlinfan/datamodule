/**
 * @file functionlist.h
 * @brief  define function list
 * @author Fan Chuanlin, fanchuanlin@aliyun.com
 * @version 1.0
 * @date 2021-01-09
 * @attention
 * @brief History:
 * <table>
 * <tr><th> Date <th> Version <th> Author <th> Description
 * <tr><td> xxx-xx-xx <td> 1.0 <td> Fan Chuanlin <td> Create
 * </table>
 *
 */

#ifndef _FUNCTION_LIST_H_
#define _FUNCTION_LIST_H_
#include "datacollecter.h"
#include "../../protocol/SimensCnc/Simens/libsiemenscnc/inc/siemenscnc.h"

extern "C"
{
    const IOFunctionList functionlist[] =
    {
        {
            0,
            0,
            3,
            NULL,
            ( pJobFunc )( siemenscnc_read_serial_number ),
        },
        {
            1,
            1,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_cnc_type,
        },
        {
            2,
            2,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_verison,
        },
        {
            3,
            3,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_manufacture_data,
        },
        {
            4,
            4,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_process_number,
        },
        {
            5,
            5,
            0,
            NULL,
            NULL,
        },
        {
            6,
            6,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_process_set_number,
        },
        {
            7,
            7,
            3,
            NULL,
            ( pJobFunc )siemenscnc_read_run_time,
        }

    };
}

#endif

