package com.ssafy.hw04.step3;

//list 나 map 으로 만들어 볼껄..
public class BookTest {
	public static void main(String[] args) throws NullPointerException{
		BookManager bm = new BookManager();
		bm.add(new Book("21424","Java Pro","김하나","jaen.kr",15000,"JAVA 기본문법"));
		bm.add(new Book("21425","Java Pro2","김하나","jaen.kr",15000,"JAVA 기본문법"));
		bm.add(new Book("35355","Java Pro3","김하나","jaen.kr",15000,"JAVA 기본문법"));
		
		Book[] bs =bm.getList();
		System.out.println("**도서목록**");
		for(Book b :bs) {
			System.out.println(b);
		}
		
		if(bm.searchByIsbn("21424")!=null){
			System.out.println("**도서조회21424**");
			System.out.println(bm.searchByIsbn("21424"));//뭔가 두번 부르는느낌
		}
		
		
		System.out.println("**도서삭제21424**");
		bm.remove("21424");
			
		bs =bm.getList();
		System.out.println("**도서목록**");
		for(Book b :bs) {
			System.out.println(b);
		}
		
		//bm.add(new Book("21424","Java Pro","김하나","jaen.kr",15000,"JAVA 기본문법"));
		
		
	}
}
