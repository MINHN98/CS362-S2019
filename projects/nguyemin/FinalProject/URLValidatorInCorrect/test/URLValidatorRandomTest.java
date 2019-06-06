package randomtest;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import URLValidator.UrlValidator;

import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class URLValidatorRandomTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testIsValid() {
		UrlValidator validator = new UrlValidator();
		
		for (int i = 0; i < 2000; i++) {
			int random_length;
			Random rnd = new Random();
			boolean expected = true;
			StringBuilder testBuffer = new StringBuilder();
					
			String SCHEME_CHARS = "httpsfh";
			
			StringBuilder scheme = new StringBuilder();
			random_length = rnd.nextInt(3)+2;
			while(scheme.length() < random_length) {
				int index = (int) (rnd.nextFloat() * SCHEME_CHARS.length());
				scheme.append(SCHEME_CHARS.charAt(index));
			}
			scheme.append(scheme.toString());
			if (scheme.toString().equals("https") || scheme.toString().equals("http") || scheme.toString().equals("ftp")) {
				expected &= true;
			}else {
				expected &= false;
			}
			testBuffer.append(scheme.toString());
			
			testBuffer.append("://");
			
			String HOST_CHARS = "qwertyuiopasdfghjklzxcvbnm";
			StringBuilder host = new StringBuilder();
			random_length = rnd.nextInt(20)+5;
			while(host.length() < random_length) {
				int index = (int) (rnd.nextFloat() * HOST_CHARS.length());
				host.append(HOST_CHARS.charAt(index));
			}
			expected &= true;

			testBuffer.append(host.toString());
			testBuffer.append(".");
			
			String DOM_CHARS = "qwertyuiopasdfghjklzxcvbnm1234567890.";
			StringBuilder domain = new StringBuilder();
			random_length = rnd.nextInt(1)+3;
			while(domain.length() < random_length) {
				int index = (int) (rnd.nextFloat() * DOM_CHARS.length());
				domain.append(DOM_CHARS.charAt(index));
			}
			if (domain.toString().matches(".*\\d.*") || domain.toString().length() <= 1) {
				expected &= false;
			}else {
				expected &= true;
			}
			testBuffer.append(domain.toString());
			
			testBuffer.append("/");
			
			String PATH_CHARS = "Q/WERT/YUIO/PASDF/GHJKLZ/XCVBNM/234567/890/.";
			StringBuilder path = new StringBuilder();
			random_length = rnd.nextInt(20)+5;
			while(path.length() < random_length) {
				int index = (int) (rnd.nextFloat() * PATH_CHARS.length());
				path.append(PATH_CHARS.charAt(index));
			}
			if (path.toString().contains("//") || path.toString().contains(".") || path.toString().startsWith("/")|| domain.toString().matches("./*\\d.*/") ) {
				expected &= false;
			}else {
				expected &= true;
			}
			testBuffer.append(path.toString());
			
			String url = testBuffer.toString();
			if (url.contains("..")) {
				expected &= false;
			}
			System.out.println(url + "\t" + expected);
			
			assertEquals(expected, validator.isValid(url));
		}
	}

}
