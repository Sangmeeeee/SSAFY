package com.ssafy.hw04.step3;

public class BookTest {
	public static void main(String[] args) {
		BookManager bm = new BookManager();
		bm.add(new Book("21424", "Java Pro", "김하나", "jean.kr", 15000, "Java 기본 문법"));
		bm.add(new Book("21425", "Java Pro2", "김하나", "jean.kr", 25000, "Java 응용"));
		bm.add(new Book("35355", "분석설계", "소나무", "jean.kr", 30000, "SW 모델링"));
		
		System.out.println("*******************************도서목록*******************************");
		Book[] books = bm.getList();
		for(int i = 0; i < BookManager.index; i++) {
			System.out.printf("%s|%s|%s|%s|%d|%s\n", 
					books[i].getIsbn(), books[i].getTitle(), books[i].getAuthor(),
					books[i].getPublisher(), books[i].getPrice(), books[i].getDesc());
		}
		
		System.out.println("*******************************도서조회: 21424*******************************");
		Book book = bm.searchByIsbn("21424");
		System.out.printf("%s|%s|%s|%s|%d|%s\n", 
				book.getIsbn(), book.getTitle(), book.getAuthor(),
				book.getPublisher(), book.getPrice(), book.getDesc());
		
		System.out.println("*******************************도서삭제: 21424*******************************");
		bm.remove("21424");
		
		System.out.println("*******************************도서목록*******************************");
		books = bm.getList();
		for(int i = 0; i < BookManager.index; i++) {
			System.out.printf("%s|%s|%s|%s|%d|%s\n", 
					books[i].getIsbn(), books[i].getTitle(), books[i].getAuthor(),
					books[i].getPublisher(), books[i].getPrice(), books[i].getDesc());
		}
	}
}
