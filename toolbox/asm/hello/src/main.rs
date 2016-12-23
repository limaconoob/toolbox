#[cfg(target_os = "linux")]
fn helloworld()
{ unsafe
  { asm!(".pushsection .rodata
      msg: .asciz \"Hello World!\"
      .popsection
      lea msg(%rip), %rdi
      call puts"); }}

fn main()
{ helloworld(); }
