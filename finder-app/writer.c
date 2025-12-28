#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char** argv) {

    // Enable logging
    openlog("writer_c", 0, LOG_USER);

    // Check for arguments
    if (argc != 3 || !argv[1]|| !argv[2]) {
        fprintf(stderr, "Missing arguments. Aborting.\nUsage: %s <file_name> <string_to_write>\n", (argc > 0 && argv[0]) ? argv[0] : "writer");
        syslog(LOG_ERR, "Missing arguments. Usage: %s <file_name> <string_to_write>", (argc > 0 && argv[0]) ? argv[0] : "writer");
        closelog();
        return EXIT_FAILURE;
    }

    const char* file_name = argv[1];
    const char* message = argv[2];

    // Log start of write process
    syslog(LOG_DEBUG, "Writing %s to %s", message, file_name);

    // Open file stream for writing. On error log and quit returning EXIT_FAILURE (1).
    FILE *file_stream = fopen(file_name, "w");
    if (!file_stream) {
        const char* error = strerror(errno);
        fprintf(stderr, "Error writing to %s. Error: %s\n", file_name, error);
        syslog(LOG_ERR, "Failed to open file %s: %s", file_name, error);
        closelog();
        return EXIT_FAILURE;
    }

    // Write character buffer to file stream. On error log and quit returning EXIT_FAILURE (1).
    if (fprintf(file_stream, "%s\n", message) < 0) {
        const char* error = strerror(errno);
        fclose(file_stream);
        fprintf(stderr, "Error writing to %s. Error: %s\n", file_name, error);
        syslog(LOG_ERR, "Failed to write to file %s: %s", file_name, error);
        closelog();
        return EXIT_FAILURE;
    }

    // Flush file stream buffer. On error log and quit returning EXIT_FAILURE (1).
    if (fflush(file_stream) != 0) {
        const char* error = strerror(errno);
        fclose(file_stream);
        fprintf(stderr, "Error writing to %s. Error: %s\n", file_name, error);
        syslog(LOG_ERR, "Failed to flush file %s: %s", file_name, error);
        closelog();
        return EXIT_FAILURE;
    }

    // Close file stream buffer. On error log and quit returning EXIT_FAILURE (1).
    if (fclose(file_stream) != 0) {
        const char* error = strerror(errno);
        fprintf(stderr, "Error writing to %s. Error: %s\n", file_name,error);        
        syslog(LOG_ERR, "Failed to close file %s: %s", file_name, error);
        closelog();
        return EXIT_FAILURE;
    }

    // Log successful operation, close the log and return EXIT_SUCCESS.
    syslog(LOG_DEBUG, "Successfully wrote %s to %s.", message, file_name);

    closelog();

    return EXIT_SUCCESS;
}
