/**
 * File:   user.h
 * Author: AWTK Develop Team
 * Brief:  user
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
 * 2019-11-01 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "tkc/str.h"
#include "tkc/mem.h"
#include "tkc/utils.h"
#include "common/user.h"

user_t* user_create(void) {
  user_t* user = TKMEM_ZALLOC(user_t);
  return_value_if_fail(user != NULL, NULL);

  str_init(&(user->name), 10);
  str_init(&(user->nick_name), 10);
  str_init(&(user->password), 10);

  return user;
}

user_t* user_copy(user_t* user, const user_t* other) {
  return_value_if_fail(user != NULL && other != NULL, NULL);

  if (user == other) {
    return user;
  }

  user->registered_time = other->registered_time;
  user->last_login_time = other->last_login_time;

  str_set(&(user->name), other->name.str);
  str_set(&(user->nick_name), other->nick_name.str);
  str_set(&(user->password), other->password.str);

  return user;
}

user_t* user_dup(const user_t* user) {
  user_t* other = NULL;
  return_value_if_fail(user != NULL, NULL);
  other = TKMEM_ZALLOC(user_t);
  return_value_if_fail(other != NULL, NULL);

  return user_copy(other, user);
}

ret_t user_auth(user_t* user, const char* password) {
  return_value_if_fail(user != NULL && password != NULL, RET_BAD_PARAMS);

  return str_eq(&(user->password), password) == TRUE ? RET_OK : RET_FAIL;
}

bool_t user_equal(user_t* user, user_t* other) {
  return_value_if_fail(user != NULL && other != NULL, FALSE);

  if (user == other) {
    return TRUE;
  }

  return user->registered_time == other->registered_time &&
         user->last_login_time == other->last_login_time &&
         str_eq(&(user->name), other->name.str) &&
         str_eq(&(user->nick_name), other->nick_name.str) &&
         str_eq(&(user->password), other->password.str);
}

int user_cmp(user_t* a, user_t* b) {
  return_value_if_fail(a != NULL && b != NULL, -1);
  return strcmp(a->name.str, b->name.str);
}

ret_t user_destroy(user_t* user) {
  return_value_if_fail(user != NULL, RET_BAD_PARAMS);

  str_reset(&(user->name));
  str_reset(&(user->nick_name));
  str_reset(&(user->password));

  TKMEM_FREE(user);

  return RET_OK;
}

bool_t user_is_admin(user_t* user) {
  return_value_if_fail(user != NULL, FALSE);

  return str_eq(&(user->name), "admin");
}
