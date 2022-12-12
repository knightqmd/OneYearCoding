#   SSRF(server-side request forgery)服务端请求伪造
### What is SSRF
    SSRF是一个web安全漏洞，它允许攻击者可以从服务器端请求访问问一些不希望被访问的地方。
1. the server make a connection to internal-only services
2. the server connect to arbitrary external systems
   
### What is the impact of SSRF attacks
1. unauthorized actions
2. access to data within the organization
3. perform arbitrary command execution

### SSRF attacks against the server itself
 在一次针对服务器本身的攻击中，攻击者引导应用应用向服务器本身发送http请求，通过它的本地回环口。
 ***在一个购物应用中会让用户查询是否某件物品在仓库中，所以为了提供仓储信息，这个应用需要询问不同的后端APIs，这个功能通过向相关后端API通过前端http request发送相应的url***
 http request(部分)
 ```
POST /product/stock HTTP/1.1
Host: 0ac500e9032cd1b7c14911050093004f.web-security-academy.net
...
stockApi=http%3A%2F%2Fstock.weliketoshop.net%3A8080%2Fproduct%2Fstock%2Fcheck%3FproductId%3D3%26storeId%3D1
 ```
由上可知当用户查询库存数量时服务器会通过请求上述url来获取仓库中物品的数量。于是我们只要修改这个url就相当于让这个服务器访问自己的某个页面**stockApi=http://localhost/admin**。
通过将stockAPI修改为http://localhost/admin，此时服务器会抓取/admin下的内容返回给用户。
（需要注意的是，管理员权限或功能通常只会给授权用户，所以攻击者如果只是简单的访问了该url并不会有什么收益，但是如果请求来自/admin URL本地机器，那么通常可以通过访问控制，因为这个请求看起来源自一个被信任的地址。）
### 本地请求被信任的原因
1. access control可能位于服务器应用程序前面的不同组件中实现，当链接返回到服务器本身时将绕过检查
2. 出于灾难恢复的情况，应用程序可能允许本地任何用户无需登录直接进行管理访问。这为管理员提供了一种丢失数据凭证时恢复系统的方法。
3. 管理界面可能侦听与主应用程序不同的端口号，因此用户可能无法直接访问。

## 针对其他后端系统的攻击
