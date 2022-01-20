package com.ssafy.ws04.step3;

public class BookTest {
	public static void main(String[] args) {
		BookManager bm = new BookManager();
		Book book1 = new Book("21424", "Java Pro", "김하나", "jaen.kr", 15000, "Java 기본 문법");
		Book book2 = new Book("21425", "Java Pro2", "김하나", "jaen.kr", 25000, "Java 응용");
		Book book3 = new Book("35355", "분석 설계\t", "소나무", "jaen.kr", 30000, "SW 모델링");		
		Book[] books;
		bm.add(book1);
		bm.add(book2);
		bm.add(book3);
		books = bm.getList();
		
		System.out.println("************************도서목록************************");
		int idx = 0;
		while(books[idx] != null) {
			System.out.println(books[idx]);
			idx++;
		}
		
		System.out.println("************************도서조회:21424************************");
		Book b = bm.searchByIsbn("21424");
		System.out.println(b);
		
		System.out.println("************************도서삭제:21424************************");
		bm.remove("21424");
		System.out.println("************************도서목록************************");
		idx = 0;
		while(books[idx] != null) {
			System.out.println(books[idx]);
			idx++;
		}
	}
}
