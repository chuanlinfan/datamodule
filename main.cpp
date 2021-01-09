#include "include/normal_typedef.h"
#include "feature/log/inc/easylogging.h"
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

INITIALIZE_EASYLOGGINGPP

void easylogginginit()
{
    // 加载配置文件，构造一个配置器对象
    el::Configurations conf( "/home/fchuanlin/datamodule/doc/log.conf" );
    // 重新配置一个单一日志记录器
    el::Loggers::reconfigureLogger( "default", conf );
    // 用配置文件配置所有的日志记录器
    el::Loggers::reconfigureAllLoggers( conf );
}


int main( int argc, char * argv[] )
{
    easylogginginit();

    LOG(INFO ) << "Start DataModule! ";

    /// 开启采集线程
    DataCollecter *pDC = new DataCollecter();
    pDC->Init();
    if( argc > 1 )
    {
        /// 读取配置文件
        pDC->InitIOListByJson( ( const CHAR * )argv[1] );
    }
    else
    {
        pDC->InitIOListByJson( ( const CHAR * )"get_param.json" );
    }

    pDC->Start();

    return 0;
}





