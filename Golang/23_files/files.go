package main

import (
	"os"
)

func main() {

	// //file
	// f, err := os.Open("exmaple.txt")
	// if err != nil {
	// 	//log the error
	// 	panic(err)
	// }

	// fileInfo, err := f.Stat()

	// fmt.Println("file name :", fileInfo.Name())
	// fmt.Println("fileor folder:", fileInfo.IsDir())
	// fmt.Println("filespermission:", fileInfo.Mode())
	// fmt.Println("file modified :", fileInfo.ModTime())

	//read file
	// f, err := os.Open("exmaple.txt")
	// if err != nil {
	// 	panic(err)
	// }

	// defer f.Close()

	// buf := make([]byte, 10)

	// d, err := f.Read(buf)
	// if err != nil {
	// 	panic(err)
	// }

	// for i:= 0; i< len(buf); i++{
	// 	println("data", d ,stirng(buf[i]))
	// }
	// println("data", d, buf)
	//3
	// data, err := os.ReadFile("example.txt")

	// if err != nil {
	// 	panic(err)
	// }
	// fmt.Println(string(data))

	//folder read
	// dir, err := os.Open(".")
	// if err != nil {
	// 	panic(err)
	// }

	// defer dir.Close()

	// fileInfo, err := dir.ReadDir(1)

	// for _, fi := range fileInfo {
	// 	fmt.Println(fi.Name(), fi.IsDir)
	// }

	//create a file
	// f, err := os.Create("example2.txt")
	// if err != nil {
	// 	panic(err)
	// }

	// defer f.Close()

	// f.WriteString("hi go")
	// f.WriteString("nice language")

	// bytes := []byte("hello go")
	// f.Write(bytes)

	// 	//read and write to another file(streaning fashion)

	// 	sourceFile, err := os.Open("example.txt")
	// 	if err != nil {
	// 		panic(err)
	// 	}

	// 	defer sourceFile.Close()

	// 	destFile, err := os.Create("example2.txt")
	// 	if err != nil {
	// 		panic(err)
	// 	}

	// 	defer destFile.Close()

	// 	reader := bufio.NewReader(sourceFile)
	// 	writter := bufio.NewWriter(destFile)

	// 	for {
	// 		b, err := reader.ReadByte()
	// 		if err != nil {
	// 			if err.Error() != "EOF" {
	// 				panic(err)
	// 			}

	// 			break
	// 		}
	// 		e := writter.WriteByte(b)
	// 		if e != nil {
	// 			panic(e)
	// 		}

	// 	}

	// 	writter.Flush()
	// 	fmt.Println("write a new file succesfully")

	//delete a file
	sourceFile, err := os.Open("example.txt")
	if err != nil {
		panic(err)
	}

	defer sourceFile.Close()

	//delete oneline soulution
	// os.Remove("example2.txt")
	// if err != nil {
	// 	panic(err)
	// }

	// fmt.Println("file deleted succesfully")
}
