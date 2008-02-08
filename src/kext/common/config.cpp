#include <sys/types.h>
#include <sys/sysctl.h>

#include "base.hpp"
#include "PCKeyboardHack.hpp"
#include "config.hpp"
#include "version.hpp"

namespace org_pqrs_PCKeyboardHack {
  Config config;

  int sysctlFunc SYSCTL_HANDLER_ARGS
  {
    int error = sysctl_handle_int(oidp, oidp->oid_arg1, oidp->oid_arg2,  req);
    if (! error && req->newptr) {
      org_pqrs_driver_PCKeyboardHack::customizeAllKeymap();
    }
    return error;
  }

  // ----------------------------------------------------------------------
  // SYSCTL staff
  // http://developer.apple.com/documentation/Darwin/Conceptual/KernelProgramming/boundaries/chapter_14_section_7.html#//apple_ref/doc/uid/TP30000905-CH217-TPXREF116
  SYSCTL_DECL(_pckeyboardhack);
  SYSCTL_NODE(, OID_AUTO, pckeyboardhack, CTLFLAG_RW, 0, "PCKeyboardHack");

  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_capslock, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_capslock), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_f3, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_f3), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_f4, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_f4), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_f5, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_f5), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_jis_xfer, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_jis_xfer), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_jis_nfer, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_jis_nfer), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, enable_jis_kana, CTLTYPE_INT|CTLFLAG_RW, &(config.enable_jis_kana), 0, &sysctlFunc, "I", "");

  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_capslock, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_capslock), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_f3, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_f3), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_f4, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_f4), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_f5, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_f5), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_jis_xfer, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_jis_xfer), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_jis_nfer, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_jis_nfer), 0, &sysctlFunc, "I", "");
  SYSCTL_PROC(_pckeyboardhack, OID_AUTO, keycode_jis_kana, CTLTYPE_INT|CTLFLAG_RW, &(config.keycode_jis_kana), 0, &sysctlFunc, "I", "");

  SYSCTL_STRING(_pckeyboardhack, OID_AUTO, version, CTLFLAG_RD, config_version, 0, "");

  // ----------------------------------------------------------------------
  void
  sysctl_register(void)
  {
    sysctl_register_oid(&sysctl__pckeyboardhack);

    sysctl_register_oid(&sysctl__pckeyboardhack_enable_capslock);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_f3);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_f4);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_f5);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_jis_xfer);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_jis_nfer);
    sysctl_register_oid(&sysctl__pckeyboardhack_enable_jis_kana);

    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_capslock);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_f3);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_f4);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_f5);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_jis_xfer);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_jis_nfer);
    sysctl_register_oid(&sysctl__pckeyboardhack_keycode_jis_kana);

    sysctl_register_oid(&sysctl__pckeyboardhack_version);
  }

  void
  sysctl_unregister(void)
  {
    sysctl_unregister_oid(&sysctl__pckeyboardhack);

    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_capslock);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_f3);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_f4);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_f5);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_jis_xfer);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_jis_nfer);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_enable_jis_kana);

    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_capslock);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_f3);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_f4);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_f5);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_jis_xfer);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_jis_nfer);
    sysctl_unregister_oid(&sysctl__pckeyboardhack_keycode_jis_kana);

    sysctl_unregister_oid(&sysctl__pckeyboardhack_version);
  }
}
