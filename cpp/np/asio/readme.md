## most of the contents come from [boost doc](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio/examples.html)

<details>
<summary>multi cast</summary>

  - sender part

    ````cpp

    class sender
    {
    public:
      sender(boost::asio::io_context& io_context,
          const boost::asio::ip::address& multicast_address)
        : endpoint_(multicast_address, multicast_port),
          socket_(io_context, endpoint_.protocol()),
          timer_(io_context),
          message_count_(0)
      {
        do_send();
      }

    private:
      void do_send()
      {
        std::ostringstream os;
        os << "Message " << message_count_++;
        message_ = os.str();

        socket_.async_send_to(
            boost::asio::buffer(message_), endpoint_,
            [this](boost::system::error_code ec, std::size_t /*length*/)
            {
              if (!ec && message_count_ < max_message_count)
                do_timeout();
            });
      }

      void do_timeout()
      {
        timer_.expires_after(std::chrono::seconds(1));
        timer_.async_wait(
            [this](boost::system::error_code ec)
            {
              if (!ec)
                do_send();
            });
      }

    private:
      boost::asio::ip::udp::endpoint endpoint_;
      boost::asio::ip::udp::socket socket_; //socket套字节
      boost::asio::steady_timer timer_;	//计时器
      int message_count_;
      std::string message_;
    };

    ````
  * receiver

    ````cpp
    class receiver
    {
    public:
      receiver(boost::asio::io_context& io_context,
          const boost::asio::ip::address& listen_address,
          const boost::asio::ip::address& multicast_address)
        : socket_(io_context)
      {
        // Create the socket so that multiple may be bound to the same address.
        boost::asio::ip::udp::endpoint listen_endpoint(
            listen_address, multicast_port);
        socket_.open(listen_endpoint.protocol());
        socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
        socket_.bind(listen_endpoint);

        // Join the multicast group.
        socket_.set_option(
            boost::asio::ip::multicast::join_group(multicast_address));

        do_receive();
      }

    private:
      void do_receive()
      {
        socket_.async_receive_from(
            boost::asio::buffer(data_), sender_endpoint_,
            [this](boost::system::error_code ec, std::size_t length)
            {
              if (!ec)
              {
                std::cout.write(data_.data(), length);
                std::cout << std::endl;

                do_receive();
              }
            });
      }

      boost::asio::ip::udp::socket socket_;
      boost::asio::ip::udp::endpoint sender_endpoint_;
      std::array<char, 1024> data_;
    };

    ````
</details>

<details>
    <summary>chatroom</summary>

define message structure:
```cpp
class chat_message
{
public:
  enum { header_length = 4 };
  enum { max_body_length = 512 };//body infomation

  chat_message()
    : body_length_(0)
  {
  }

  const char* data() const
  {
    return data_;
  }

  char* data()
  {
    return data_;
  }

  std::size_t length() const
  {
    return header_length + body_length_;
  }

  const char* body() const
  {
    return data_ + header_length;
  }
  
  char* body()
  {
    return data_ + header_length;
  }

  std::size_t body_length() const
  {
    return body_length_;
  }

  void body_length(std::size_t new_length)
  {
    body_length_ = new_length;
    if (body_length_ > max_body_length)
      body_length_ = max_body_length;
  }

  bool decode_header()
  {
    char header[header_length + 1] = "";
    std::strncat(header, data_, header_length);
    body_length_ = std::atoi(header);
    if (body_length_ > max_body_length)
    {
      body_length_ = 0;
      return false;
    }
    return true;
  }

  void encode_header()
  {
    char header[header_length + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(body_length_));
    std::memcpy(data_, header, header_length);
  }

private:
  char data_[header_length + max_body_length];
  std::size_t body_length_;
};
```

</details>

