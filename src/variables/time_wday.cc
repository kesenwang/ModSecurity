/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2020 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/variables/time_wday.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

#include "modsecurity/transaction.h"

namespace modsecurity {
namespace variables {

void TimeWDay::evaluate(const Transaction *transaction,
    VariableValues *l) const noexcept {
    char tstr[200];
    struct tm timeinfo;
    time_t timer;

    time(&timer);
    memset(tstr, '\0', 200);

    localtime_r(&timer, &timeinfo);
    strftime(tstr, 200, "%u", &timeinfo);

    l->push_back(std::make_shared<VariableValue>(
        std::unique_ptr<std::string>(new std::string(tstr)),
        &m_retName));
}


}  // namespace variables
}  // namespace modsecurity
