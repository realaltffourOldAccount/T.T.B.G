// Utils Bundle includes all utils in one include
// Should not be included by any utils files
// If there is need to include a util file to build another util
// file, include individualy is adviced

#ifndef UTILS_BUNDLE_H
#define UTILS_BUNDLE_H

// Define this to remove asserts
//#define NDEBUG
#include <assert.h>
#include <algorithm>
#include <iomanip>

#include "../files/File_Manager.h"
#include "../files/csv/csv_loader.h"
#include "../files/csv/csv_saver.h"
#include "../files/file_util.h"

#include "../log/Log.h"

#include "../misc/finder.h"
#include "../misc/json.hpp"
#include "../misc/random_rework.h"
#include "../misc/string_util.h"

#include "../time/Timer.h"
#endif