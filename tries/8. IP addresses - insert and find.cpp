/*
  You are given a set of IP addressess and hostnames as shown below. You are supposed to write the code for 2 methods 
  Insert
  which takes an IP address and hostname and stores it
  Find
  which takes in an IP address and returns the hostname(s)
  e.g below the list of the IP address and Hostnames
  1.2.3.4 a.com
  1.2.3.5 b.com
  1.2.3.6 c.com
  1.6.2.4 d.com
  Insert(1.2.3.4 , a.com) 
  Insert(1.2.3.5 , b.com) 
  Insert(1.2.3.6 , c.com) 
  Insert(1.6.2.4 , d.com) 
  Find(1.2.3.4 ) must return {a.com}
  Find(1.2.3.) must return {a.com, b.com, c.com}
  Find(1.) must return {a.com, b.com,c.com, d.com}
  Find(2.) must return {}
*/
