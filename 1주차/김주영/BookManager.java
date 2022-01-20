package com.ssafy.ws04.step3;

public class BookManager {
	private int MAX_SIZE = 100;
	private Book[] books = new Book[MAX_SIZE];
	private int size = 0;
	
	public void add(Book book) {
		if(size > MAX_SIZE)	{
			System.out.println("더 이상 도서를 등록할 수 없습니다.");
			return;
		}
		books[size++] = book;
	}
	
	public void remove(String isbn) {
		int idx;
		for(idx=0; idx<size; idx++) {
			if(books[idx].getIsbn().equals(isbn))
				break;
		}
		for(int i=idx; i<size-1; i++) {
			books[i] = books[i+1];
		}
		books[size-1] = null;
		size--;
	}
	
	public Book[] getList() {
		return books;
	}
	
	public Book searchByIsbn(String isbn) {
		Book b = new Book();
		for(int i=0; i<size; i++) {
			if(books[i].getIsbn().equals(isbn))	{
				b =  books[i];
			}
		}
		return b;
	}
}
