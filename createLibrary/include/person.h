/** @file person.h
 * 联系人定义
 * 
 */
#ifndef INCLUDE_PERSON_H_
#define INCLUDE_PERSON_H_

#include<string>

using std::string;


/**
 * 联系人定义
 */
class Person {
public:

	/**
	 * 默认构造方法
	 */
	Person();
	/** 自定义的构造方法
	 * 
	 * @param name 姓名
	 * @param phone 电话
	 * @param email 邮箱
	 */
	Person(string name, string phone, string email);
	~Person();

	/** 输出联系人的信息
	 * 
	 * @return 包含联系人信息的一个std::string字符串
	 */
	string toString();

	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getName() const;
	void setName(const string& name);
	const string& getPhone() const;
	void setPhone(const string& phone);

private:
	/**< 姓名  */
	string name;
	/**< 电话  */
	string phone;
	/**< 邮箱  */
	string email;
};

#endif /* INCLUDE_PERSON_H_ */