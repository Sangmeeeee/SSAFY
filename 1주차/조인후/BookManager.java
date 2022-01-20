package com.ssafy.hw04.step3;

public class BookManager {
	private int MAX_SIZE = 100;
	private Book[] book = new Book[MAX_SIZE];
	private int size;
	static int index = 0;
	
	public void add(Book book) {
		this.book[index++] = book;
	}
	
	public void remove(String isbn) {
		for(int i = 0; i < index; i++) {
			if(book[i].getIsbn().equals(isbn)) {
				if(i == index - 1)
					book[i] = null;
				else {
					for(int j = i + 1; j < index; j++)
						book[j - 1] = book[j];
					book[index - 1] = null;
				}
				index--;
				break;
			}
		}
	}
	
	public Book[] getList() {
		return book;
	}
	
	public Book searchByIsbn(String isbn) {
		for(Book b: book)
			if(b.getIsbn().equals(isbn))
				return b;
		return null;
	}
}
