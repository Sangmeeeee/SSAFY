package com.ssafy.hw04.step3;

import java.util.Arrays;

public class BookManager  {
	private int MAX_SIZE;//안쓰는데?
	private Book[] books;
	private int size;//안쓰는데?
	
	public void add(Book book){
		if (books==null) {//아하 여기 한수 배웠다. 난 books.length==0 했는데 NullPointerException 뜨더라 (book 을 못가리켜서)
			books = new Book[1];
			books[0]=book;
		}
		else {//중복 제외 하는거 원래 해야함.
			//늘리는거 봐두기
			Book [] newarr = Arrays.copyOf(books, books.length+1);
			books = newarr;
			//book idx 마지막에 추가.
			books[books.length-1]=book;
		}
	}
	public void remove(String isbn) {//
		int idx=-1;
		//동일 isbn 탐색
		for(int i =0;i<books.length ; i++) {
			if(books[i].getIsbn()==isbn) {
				idx =i;
				break;
			}
		}
		if(idx!=-1) {
			for(int i=idx;i< books.length -1 ;i++) {
				books[i] = books[i+1];
			}
			//엉망진창이구만 차라리 리스트 쓰지 진짜
			//하나 줄여주는
			Book [] newarr = Arrays.copyOf(books, books.length-1);
			books = newarr;
		}
		
	}
	public Book[] getList() {
		return books;
	}
	public Book searchByIsbn(String isbn) {
		for(Book b:books) {
			if(b.getIsbn()==isbn) {
				return b;
			}
		}
		return null;
	}
}
