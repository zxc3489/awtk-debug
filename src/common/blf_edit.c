/**
 * Created by liangshengfeng on 2020/11/9.
 * Copyright (c) 2020 star-net. All rights reserved.
 */

#include "blf_edit.h"
#include "tkc/mem.h"
#include "app_globals.h"
#include "mvvm/base/navigator.h"
#include "tkc/timer_info.h"

enum{
    BLF_EDIT_ITEM_PHONE_ID,
    BLF_EDIT_ITEM_ACCOUNT,
    BLF_EDIT_ITEM_MAX,
};

#define default_key_up(selected,max) { \
    if(selected <= 0){ \
        selected = max - 1; \
    }else{ \
        selected--; \
    } \
    static_selected = selected; \
}

#define default_key_down(selected,max) { \
    if(selected >= max -1){ \
        selected = 0; \
    }else{ \
        selected++; \
    } \
    static_selected = selected; \
}

#define BLF_EDIT_ITEM_LEN BLF_EDIT_ITEM_MAX

static int static_selected = 0;

static ret_t __test_timer(const timer_info_t *info)
{
  navigator_to("user_add");
  return RET_REMOVE;
}

blf_edit_t *blf_edit_create()
{
    blf_edit_t *settings = TKMEM_ZALLOC(blf_edit_t);
    return_value_if_fail(settings != NULL, NULL);
    settings->selected = BLF_EDIT_ITEM_PHONE_ID;
    emitter_init(EMITTER(settings));
    timer_add(__test_timer, NULL, 15000);
    return settings;
}

ret_t blf_edit_destroy(blf_edit_t *blf_edit)
{
    return_value_if_fail(blf_edit != NULL, RET_BAD_PARAMS);
    emitter_deinit(&blf_edit->emitter);
    TKMEM_FREE(blf_edit);
    return RET_OK;
}

ret_t blf_edit_key_up(blf_edit_t *blf_edit)
{
    return_value_if_fail(blf_edit != NULL, RET_BAD_PARAMS);
    default_key_up(blf_edit->selected, BLF_EDIT_ITEM_LEN);
    log_error("======%s\n",__FUNCTION__);
    return RET_OBJECT_CHANGED;
}

ret_t blf_edit_key_down(blf_edit_t *blf_edit)
{
    return_value_if_fail(blf_edit != NULL, RET_BAD_PARAMS);
    default_key_down(blf_edit->selected, BLF_EDIT_ITEM_LEN);
    log_error("======%s\n",__FUNCTION__);
    return RET_OBJECT_CHANGED;
}
