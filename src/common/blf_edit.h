/**
 * Created by liangshengfeng on 2020/11/9.
 * Copyright (c) 2020 star-net. All rights reserved.
 */

#ifndef AWTK_MVVM_C_BLF_EDIT_H
#define AWTK_MVVM_C_BLF_EDIT_H

#include "tkc/darray.h"
#include "tkc/emitter.h"
#include "mvvm/base/navigator.h"

/**
 * @class blf_edit_t
 * @parent emitter_t
 *  blf_edit配置控制器
 * @annotation ["model"]
 * */
typedef struct _blf_edit_t {
    emitter_t emitter;
    /**
     * @property {int} selected
     * 所选项从0开始
     * @annotation ["readable", "writable"]
     * */
    int selected;
    /**
     * @property {int} key
     * 按键
     * @annotation ["readable", "writable"]
     * */
    int key;
    /**
     * @property {int} phone_id
     * 线路
     * @annotation ["readable", "writable"]
     * */
    int phone_id;
    /**
     * @property {str_t} label
     * 订阅的号码
     * @annotation ["readable", "writable"]
     * */
    str_t label;
} blf_edit_t;

/**
 * @method blf_edit_create
 * 构造函数
 * @annotation ["constructor"]
 * @return {blf_edit_t*} 返回blf_edit model对象
 * */
blf_edit_t *blf_edit_create();

/**
 * @method blf_edit_destroy
 * @annotation ["destructor"]
 * 销毁函数
 * @param {blf_edit_t*} blf_edit_t 对象
 * @return {ret_t} RET_OK 成功
 * */
ret_t blf_edit_destroy(blf_edit_t *blf_edit);

/**
 * @method blf_edit_key_up
 * 监听上方向键
 *
 * @annotation ["command"]
 * @param {blf_edit_t*} blf_edit blf_edit 对象。
 *
 * @return {ret_t} 返回 RET_OK 表示成功；
 * 返回 RET_OBJECT_CHANGED 表示 Model 有变化，View 需要刷新；返回其它表示失败。
 */
ret_t blf_edit_key_up(blf_edit_t *blf_edit);

/**
 * @method blf_edit_key_down
 * 监听下方向键
 *
 * @annotation ["command"]
 * @param {blf_edit_t*} blf_edit blf_edit 对象。
 *
 * @return {ret_t} 返回 RET_OK 表示成功；
 * 返回 RET_OBJECT_CHANGED 表示 Model 有变化，View 需要刷新；返回其它表示失败。
 */
ret_t blf_edit_key_down(blf_edit_t *blf_edit);
#endif //AWTK_MVVM_C_BLF_EDIT_H
