/**
 * File:   application.c
 * Author: AWTK Develop Team
 * Brief:  application
 *
 * Copyright (c) 2018 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-10-29 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"
#include "mvvm/mvvm.h"

#include "assets.inc"
#include "view_models/login_view_model.h"
#include "view_models/user_add_view_model.h"
#include "view_models/blf_edit_view_model.h"

ret_t application_init() {
  mvvm_init();

#if !defined(ANDROID) && !defined(IOS)
  window_open("system_bar");
#endif

  view_model_factory_register("login", login_view_model_create);
  view_model_factory_register("user_add", user_add_view_model_create);
  view_model_factory_register("blf_edit",blf_edit_view_model_create);

  return navigator_to("blf_edit");
}

#include "mvvm/mvvm.h"

ret_t application_exit() {
  log_debug("application_exit\n");
  mvvm_deinit();
  return RET_OK;
}

#include "awtk_main.inc"
