use std::ffi::c_void;

extern "C" {
    pub fn libexample_init() -> *mut c_void;
    pub fn libexample_inc(data: *mut c_void);
    pub fn libexample_deinit(data: *mut c_void);
}
