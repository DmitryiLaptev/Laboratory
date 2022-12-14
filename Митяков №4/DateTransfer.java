package sample;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class DateTransfer {
    private static final String DATE_PATTERN = "dd.MM.yyyy";
    private static final DateTimeFormatter DATE_FORMATTER =
            DateTimeFormatter.ofPattern(DATE_PATTERN);
    private static final String TIME_PATTERN = "HH:mm";
    private static final DateTimeFormatter TIME_FORMATTER =
            DateTimeFormatter.ofPattern(TIME_PATTERN);

    public static String formatTime(LocalTime time){
        if(time == null)
            return null;
        return TIME_FORMATTER.format(time);
    }

    public static LocalTime parseTime(String timeString){
        try{
            return TIME_FORMATTER.parse(timeString, LocalTime::from);
        } catch (DateTimeParseException e){
            return null;
        }
    }

    public static String formatDate(LocalDate date){
        if(date == null)
            return null;
        return DATE_FORMATTER.format(date);
    }
    public static LocalDate parseDate(String dateString) {
        try {
            return DATE_FORMATTER.parse(dateString, LocalDate::from);
        } catch (DateTimeParseException e) {
            return null;
        }
    }
}
