#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true (executable command exists), 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void)info; // Unused parameter, suppress compiler warning.

    // Check if the path is valid and if it's a regular file.
    if (!path || stat(path, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1); // It's a regular file, indicating an executable command.
    }
    return (0); // It's not an executable command.
}

/**
 * dup_chars - Duplicates characters within a string.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to a new buffer containing the duplicated characters.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buf[1024]; // Static buffer for storing duplicated characters.
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    }
    buf[k] = 0; // Null-terminate the duplicated characters.
    return (buf);
}

/**
 * find_path - Finds the full path of a command within the PATH string.
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);

    // Check if the command starts with "./" and if it's an executable command.
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            // Extract a path segment from pathstr.
            path = dup_chars(pathstr, curr_pos, i);

            // Append the command to the extracted path.
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            // Check if the combined path is an executable command.
            if (is_cmd(info, path))
                return (path);

            if (!pathstr[i])
                break; // Reached the end of pathstr.

            curr_pos = i;
        }
        i++;
    }

    return (NULL); // Command not found in any path segment.
}

