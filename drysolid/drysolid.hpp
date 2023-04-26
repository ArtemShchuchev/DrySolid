#pragma once

#include <string>
#include <iostream>
#include <fstream>

/*
    Принцип разделения интерфейса
    "Толстый интерфейс"


class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};
*/

/*
    Принцип подстановки Лисков
    Ожидается, что функции форматирования текста, отдадут std::string, но 
    они могут выбросить исключения. Я не понимаю... Исключения использовать нельзя?
    Ведь они всегда нарушают ход программы, а стало быть принцип Лискова?

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};
*/

class Format
{
public:
    virtual ~Format() = default;

    virtual std::string formatting() const = 0;
};

class FormatAsHTML : public Format
{
private:
    std::string data_;
public:
    FormatAsHTML(const std::string& data) : data_(data) {}
    std::string formatting() const override
    {
        return "<html>" + data_ + "<html/>";
    }
};

class FormatAsText : public Format
{
private:
    std::string data_;
public:
    FormatAsText(const std::string& data) : data_(data) {}
    std::string formatting() const override
    {
        return data_;
    }
};

class FormatAsJSON : public Format
{
private:
    std::string data_;
public:
    FormatAsJSON(const std::string& data) : data_(data) {}
    std::string formatting() const override
    {
        return "{\"data\": \"" + data_ + "\"}";
    }
};
