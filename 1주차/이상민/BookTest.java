package step3;

public class BookTest {
	public static void main(String[] args) {
		BookManager bookManager = new BookManager();
		bookManager.add(new Book("21424", "Java Pro", "김하나", "jaen.kr", 15000, "Java 기본 문법"));
		bookManager.add(new Book("21425", "Java Pro2", "김하나", "jaen.kr", 25000, "Java 응용"));
		bookManager.add(new Book("35355", "분석설계", "소나무", "jaen.kr", 30000, "SW 모델링"));
		
		for(Book book : bookManager.getList()) {
			System.out.println(book);
		}
		
		System.out.println("도서 조회 21424");
		System.out.println(bookManager.searchByIsbn("21424"));
		
		System.out.println("도서 삭제 21424");
		bookManager.remove("21424");
		for(Book book : bookManager.getList()) {
			System.out.println(book);
		}

		System.out.println("도서 삭제 35355");
		bookManager.remove("35355");
		for(Book book : bookManager.getList()) {
			System.out.println(book);
		}

		System.out.println("도서 조회 21425");
		System.out.println(bookManager.searchByIsbn("21425"));
	}
}
