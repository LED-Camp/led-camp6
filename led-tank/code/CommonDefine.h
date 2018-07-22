#ifndef __COMMON_DEFINE_H__

/* *** 2重イングルード禁止 *** */
#define __COMMON_DEFINE_H__

/* *** ファイルインクルード *** */


/* *** 定数定義 *** */
#define RET_SUCCESS  (0)                    // 戻り値: 成功
#define RET_FAILED   (-1)                   // 戻り値: 失敗
#define RET_INVALID_FD  (-21)
#define RET_FAILED_REGWR  (-11)
#define RET_FAILED_MATCH  (-12)
#define RET_TRUE     (1)                    // 戻り値: bool真
#define RET_FALSE    (0)                    // 戻り値: bool偽

#define RET_UNINIT   (1)
#define RET_ERR_UNINIT (0)

/* *** 型定義 *** */
typedef enum _enLedSliderPos_t {
  POS_A = 0,
  POS_B,
  POS_C,
  POS_D
} enLEDSliderPos_t;

typedef enum _enColor_t {
    COL_BASE = 0x90,
    COL_RED,
    COL_GRN,
    COL_BLE,
    COL_YLW,
    COL_CYN,
    COL_MGT,
    COL_WHT,
    COL_BLK,
    COL_LAST
} enColor_t;

typedef enum _enRole_t {
    ROLE_PLAYER = 0x30,             // 参加者サイド
    ROLE_JUDGE  = 0x40              // 運営サイド
} enRole_t;

/* メッセージID */
typedef enum _enMsgId_t {
    /* for Player */
    PLAYER_HELLO = (ROLE_PLAYER + 1),   // 接続要求
    PLAYER_UPDATE,                      // 点数更新要求
    PLAYER_START,                       // センシング開始要求
    PLAYER_ABORT,                       // センシング中止要求
    PLAYER_BYE,                         // 切断要求
    /* for Judge */
    JUDGE_HELLO = (ROLE_JUDGE + 1),     // 接続応答
    JUDGE_BUSY,                         // 接続不可応答
    JUDGE_DEAL,                         // 配点通知
    JUDGE_ACK,                          // 肯定応答
    JUDGE_NACK,                         // 否定応答
    JUDGE_OK,                           // 正常応答
    JUDGE_NG,                           // 異常応答
    JUDGE_TIMEOUT,                      // タイムアウト通知
    JUDGE_BYE                           // 切断通知
} enMsgId_t;

/* *** マクロ関数 *** */
#define ARRAY_SIZE(x)      (sizeof(x) / sizeof(x[0]))
#define NUM_DEFAULT_COLOR  (COL_LAST - COL_BASE + 1)
#define INDEX_COLOR(x)     ((x) - COL_BASE)

#endif /* __COMMON_DEFINE_H__ */
