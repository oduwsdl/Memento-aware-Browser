# Chromite CLI Framework

This directory contains the core CLI system.

[TOC]

## Adding a new command

New commands can be added by creating a new file in `cros/` that follows
the `cros_{command_name}.py` format where the command can live.

The command class's implementation _must_:
*   Be a subclass of `cli.command.Command`
*   Have a `@command.CommandDecorator('command-name')` decorator on the class
*   Define an `EPILOG` class constant
*   Implement the `@classmethod` `AddParser(cls, parser)`
*   Implement `Run(self)`

Rules of thumb:
*   The `Run` method _should not_ be a full implementation of the command.
    *   It _should_ validate the raw arguments.
    *   It _should_ translate arguments to chromite constructs as applicable.
    *   It should then call a reusable implementation (e.g. in `service/`).
    *   Otherwise, it _may_ be a wrapper around a command outside of chromite.

## Argument Parser

Chromite has a subclass of `argparse.ArgumentParser` in the `lib.commandline`
module.
The `ArgumentParser` subclass adds some common functionality, and a set of
standard arguments that all scripts can take advantage of.

### Custom Argument Types

There are a number of custom types defined for the `ArgumentParser`,
which can be used with `type='custom_type_name'`.

*   ab_url: Parse android build urls.
*   bool: Parse standard shell boolean values (y/yes, n/no, 1, 0, true, false).
*   build_target: Does a regex validation of the name and produces a
    BuildTarget instance.
*   date: Parse the argument as a Y-m-d formatted date.
*   path: Expands ~/ paths and then standardizes to the real path.
*   gs_path: Processes all known GS urls and provides the equivalent gs:// url.
*   local_or_gs_path: Processes the argument as a 'path' or a 'gs_path',
    as needed.
*   path_or_uri: Like local_or_gs_path, but also parse other uri formats.

### Argument Deprecation Functionality

The `ArgumentParser` also provides support for the `deprecated` argument in the
`ArgumentParser.add_argument` method.
This argument allows marking an argument as deprecated by printing a warning
message, but still processes the argument as it normally would.
Using the `--foo` argument below would produce something like the following log
message.

```python
parser.add_argument('--foo', type=int, deprecated='Use --bar instead!')
```

```text
Argument --foo is deprecated: Use --bar instead!
```

### Defined Arguments

*   --log-level: The minimum logging level (default: notice).
*   --log-format: Change log line format.
*   -v/--verbose: Sets the verbose option to true and sets the log-level to
    info.
*   --debug: Sets verbose and debug options to true and sets the log-level to
    debug.
*   --nocolor: Disable log coloring.
*   --cache-dir: Override the cache directory when caching is enabled in the
    parser.

## Argument Standards

There are only a few style rules on top of the standard rules imposed by the
python `ArgumentParser`.
Dashes should be preferred over underscores, e.g. `--argument-name`,
**not** `--argument_name`.
If there is historical context for `--argument_name`, it *may* be included,
but `--argument-name` *must* also be included.

For negative flag arguments, use --no-foo instead of --nofoo, and store it to
foo. e.g.

```python
parser.add_argument('--no-foo', dest='foo', action='store_false', default=True)
```

### Standard Arguments

Generally scripts are welcome to use any arguments they need.
However, in the interest of standardizing the tools, some arguments have been
defined as being reserved for specific usages.
Not all the arguments will always apply, but when they are used, this is the
form they must have.

| Short | Long | Description |
|---|---|---|
| -b | --build-target | [Build Target](#Build-Target) |
| -d | --device | [Device](#Device) |
| -f | --force | [Force](#Force) |
| -j | --jobs | [Jobs](#Jobs) |
| -n | --dry-run | [Dry Run](#Dry-Run) |
| | package(s) | [Packages](#Packages) |
| -y | --yes | [Yes](#Yes) |

#### Build Target

This is the new version of the `--board` option that is in scripts pre-dating
the standards.
The build target option comes with parsing support in the form of the
build_target type.
The build target type will validate the name and construct a
[BuildTarget](https://chromium.googlesource.com/chromiumos/chromite/+/refs/heads/master/lib/build_target_lib.py)
instance to assign to the variable rather than just storing the string.

```python
parser.add_argument('-b', '--build-target', type='build_target')
```

#### Device

The device argument is a long-standing type that just did not always use the
same argument naming conventions.
The device parser supports USB, File, SSH, and Servo.
A specific device argument can accept any or all of the supported types.
The example below supports USB and File, but not SSH or Servo.

```python
parser.add_argument(
    '-d', '--device',
    type=commandline.DeviceParser([commandline.DEVICE_SCHEME_USB,
                                   commandline.DEVICE_SCHEME_FILE]))
```

#### Dry Run

A dry-run of a script should log information about steps it would be taking
without executing operations that mutate anything.
Implementing a dry-run for your script is very strongly recommended.
A dry-run allows developers to more quickly experiment with and verify their
usage and understanding of your script, and empowers them to make mistakes
without worrying about consequences.

There are tentative plans to implement the dry-run argument as a default
on our ArgumentParser subclass, making it available for all the commands.
If done, any existing inclusions will be converted, so until then please feel
free to add it to your script.

```python
parser.add_argument(
    '-n',
    '--dryrun',
    '--dry-run',
    dest='dryrun',
    action='store_true',
    default=False)
```

#### Force

The force argument should only be used when there's an operation to "force"
to complete that would otherwise abort, e.g. deleting an existing X, if it
exists, to create a new X.
If the operation would prompt the user, then [--yes](#Yes) is the correct option.

```python
parser.add_argument('-f', '--force', action='store_true', default=False)
```

#### Jobs

This argument is used to specify maximum parallelism for concurrent tasks.
The default should be unlimited when feasible, or the machine's CPU count
when not.
If unsure, lean towards unlimited and adjust if/when it is a problem.
In particular, this helps avoid chained calls from unexpectedly being limited.

```python
parser.add_argument('-j', '--jobs', type=int, default=0)
```

#### Packages

The package(s) argument should be a positional argument taking one or more
packages as appropriate.
The requirements for what must be included in the specified package(s) are
dependent on the script itself.

```python
parser.add_argument('packages', nargs='+')
```

#### Yes

The yes option is a pretty common argument to allow the user to skip manually
confirming prompts and instead assume the user confirmed each case.

```python
parser.add_argument('-y', '--yes', action='store_true', default=False)
```
