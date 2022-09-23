package sample;


import javafx.beans.property.*;
import javafx.util.converter.LocalDateTimeStringConverter;

import java.sql.Time;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

public class Call {
    private IntegerProperty pNumber;
    private StringProperty name1;
    private StringProperty name2;
    private IntegerProperty callDuration;
    private ObjectProperty<LocalDate> date;

    private ObjectProperty<LocalTime> time;

    public Call(Integer pNumber, String name1, String name2, Integer callDuration,
                Integer year, Integer mouth, Integer day,
                Integer hour, Integer minute) {
        this.pNumber = new SimpleIntegerProperty(pNumber);
        this.name1 = new SimpleStringProperty(name1);
        this.name2 = new SimpleStringProperty(name2);
        this.callDuration = new SimpleIntegerProperty(callDuration);
        this.date = new SimpleObjectProperty<LocalDate>(LocalDate.of(year,mouth,day));
        this.time = new SimpleObjectProperty<LocalTime>(LocalTime.of(hour, minute));
    }
    public Call(){}

    public int getpNumber() { return pNumber.get(); }
    public IntegerProperty pNumberProperty() {
        return pNumber;
    }
    public void setpNumber(int pNumber) {
        this.pNumber.set(pNumber);
    }

    public String getName1() {
        return name1.get();
    }
    public StringProperty name1Property() {
        return name1;
    }
    public void setName1(String name1) {
        this.name1.set(name1);
    }

    public String getName2() {
        return name2.get();
    }
    public StringProperty name2Property() {
        return name2;
    }
    public void setName2(String name2) {
        this.name2.set(name2);
    }

    public int getCallDuration() {
        return callDuration.get();
    }
    public IntegerProperty callDurationProperty() {
        return callDuration;
    }
    public void setCallDuration(int callDuration) {
        this.callDuration.set(callDuration);
    }

    public LocalDate getDate() { return date.get(); }
    public ObjectProperty<LocalDate> dateProperty() { return date; }
    public void setDate(LocalDate date) { this.date.set(date); }

    public LocalTime getTime() { return time.get(); }
    public ObjectProperty<LocalTime> timeProperty() { return time; }
    public void setTime(LocalTime time) { this.time.set(time); }
}
