
use rayon::slice::ParallelSliceMut;
use std::io::prelude::*;
use std::io::{self, BufReader};
use std::fs::File;
use input_stream::InputStream;
use std::time::Instant;
use floating_duration::TimeFormat;

fn main() -> io::Result<()> {
  
    // 파일 읽기 =================================================
    let mut input = InputStream::new(
        BufReader::new(File::open("data70M-1").expect("a file")));
    let mut lst = Vec::new();
    let mut value: i32 = 0;

    loop {
        value = match input.scan() {
            Ok(value) => value,
            Err(_e_) => break,
        };
        lst.push(value);
    }
  
    // 시간 측정 =================================================
    let now = Instant::now();              // 측정 시작!

    lst.par_sort_unstable();               // 정렬

    let time = TimeFormat(now.elapsed());  // 측정 끝!
    println!("경과시간: {}", time);


    // 파일에 쓰기 ===============================================
    let mut wb = File::create("output")?;
    let mut i = 0;

    for item in &lst {
        wb.write_all(format!("{:10} ", item).as_bytes())?;
        i += 1;
        if i % 5 == 0 {
            wb.write_all(b"\n")?;
        }
    }

    Ok(())
}
