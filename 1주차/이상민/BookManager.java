package step3;

import java.util.Arrays;

public class BookManager {
	private final int MAX_SIZE = 100;
	private Book[] books = new Book[MAX_SIZE];
	private int size = 0;
	
	public void add(Book book) {
		books[size++] = book;
	}
	
	public void remove(String isbn) {
		int reorder = 0;
		for(int i = 0; i < size; i++) {
			if(books[i].getIsbn().equals(isbn)) {
				books[i] = null;
				reorder = i;
				break;
			}
		}
		
		for(;reorder < size - 1; reorder++) {
			books[reorder] = books[reorder+1];
		}
		size--;
	}
	
	public Book[] getList() {
		return Arrays.copyOf(books, size);
	}
	
	public Book searchByIsbn(String isbn) {
		for(int i = 0; i < size; i++) {
			if(books[i].getIsbn().equals(isbn)) {
				return books[i];
			}
		}
		return null;
	}
}
