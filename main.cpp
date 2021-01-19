#include "include/normal_typedef.h"
#include "feature/easyloggingpp/src/easylogging++.h"
#include "thirdparty/restclient/include/restclient-cpp/restclient.h"
#include "common/typeany/inc/typeany.h"


#include "product/inc/datacollecter.h"
/// 西门子CNC test
#include "protocol/SimensCnc/Simens/libsiemenscnc/inc/siemenscnc.h"
#include "protocol/SimensCnc/Simens/libsiemenscnc/828d/siemens_828d_new.h"

/// JSON
#include "include/json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

#ifdef ELPP_THREAD_SAFE

INITIALIZE_EASYLOGGINGPP

#endif

#if ELPP_FEATURE_CRASH_LOG
void myCrashHandler( int sig )
{
    LOG( ERROR ) << "Woops! Crashed!";
    // FOLLOWING LINE IS ABSOLUTELY NEEDED AT THE END IN ORDER TO ABORT APPLICATION
    el::Helpers::crashAbort( sig );
}

#endif

void easylogginginit()
{
    // 加载配置文件，构造一个配置器对象
    el::Configurations conf( "/home/fchuanlin/datamodule/doc/log.conf" );
    // 重新配置一个单一日志记录器
    el::Loggers::reconfigureLogger( "default", conf );
    // 用配置文件配置所有的日志记录器
    el::Loggers::reconfigureAllLoggers( conf );

#if ELPP_FEATURE_CRASH_LOG
    el:: Helpers::setCrashHandler( myCrashHandler );
#endif
}


int main( int argc, char * argv[] )
{
    BOOLEAN bret = FALSE;

    easylogginginit();
    LOG( INFO ) << "Start DataModule! ";
    /// 开启采集线程
    DataCollecter *pDC = new DataCollecter();
    pDC->Init();
    if( argc > 1 )
    {
        /// 读取配置文件
        bret = pDC->InitIOListByJson( ( const CHAR * )argv[1] );
    }
    else
    {
        bret = pDC->InitIOListByJson( ( const CHAR * )"get_param.json" );
    }

    if( bret )
    {
        pDC->Start();
    }

    return 0;
}





